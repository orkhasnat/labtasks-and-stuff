if(!require("BiocManager", quietly = TRUE))
  install.packages("BiocManager")

BiocManager::install(version = "3.17")
BiocManager::install("TCGAbiolinks")




library(TCGAbiolinks)

library(SummarizedExperiment)


project<-c("TCGA-UCEC")
projectfile <- c("tcga.rda")

query <- GDCquery(project = project,
                  data.category = "Transcriptome Profiling",
                  data.type = "Gene Expression Quantification",
                  workflow.type = "STAR - Counts")

GDCdownload(query, method="api")


data <- GDCprepare(query = query, summarizedExperiment = TRUE)
SummarizedExperiment <- GDCprepare(query = query, summarizedExperiment = TRUE)
save(SummarizedExperiment, file = projectfile)


mRNAi <- elementMetadata(SummarizedExperiment)$gene_type == "protein_coding"

SummarizedExperiment <- SummarizedExperiment[mRNAi, ]

normal <- which(colData(SummarizedExperiment)$sample_type == "Solid Tissue Normal")
cntN <- length(normal)

seN <- SummarizedExperiment[, normal] # Solid Tissue Normal samples.
seDFN <- assays(seN)$unstranded

tumor <- which(colData(SummarizedExperiment)$sample_type == "Primary Tumor") 
cntT <- length(tumor) 

seT <- SummarizedExperiment[, tumor] # "Primary Tumor" sample type.
seDFT <- assays(seT)$unstranded

countdata <- cbind(seDFN, seDFT) # Combine the "unstranded" assay data from both normal and tumor samples into a single matrix "countdata"

samplesN <- colnames(seDFN)
samplesT <- colnames(seDFT)

conditionN <- rep("Normal", cntN)
conditionT <- rep("Tumor", cntT)

dfN <- data.frame(samples = samplesN, condition = conditionN)
dfT <- data.frame(samples = samplesT, condition = conditionT)

coldata <- rbind(dfN, dfT)  # Combine the data frames for normal and tumor samples into a single data frame "coldata"
coldata$condition <- as.factor(coldata$condition)



BiocManager::install("DESeq2")

library(DESeq2)

if (!require("BiocManager", quietly = TRUE))
  install.packages("BiocManager")
BiocManager::install("DESeq2")



dds <- DESeqDataSetFromMatrix(countData = countdata, colData = coldata, design = ~condition)
dds <- DESeq(dds)

plotMA(results(dds))

res <- results(dds)

# Remove rows with missing log2 fold-change values
res <- res[!is.na(res$log2FoldChange), ]

# Order the results by adjusted p-value
res <- res[order(res$padj), ]

upregulated_genes <- res[res$log2FoldChange > 0, ][1:250, ]
downregulated_genes <- res[res$log2FoldChange < 0, ][1:250, ]

head(upregulated_genes)
write.csv(upregulated_genes, "top_upregulated_genes.csv", row.names = FALSE)

head(downregulated_genes)
write.csv(downregulated_genes, "top_downregulated_genes.csv", row.names = FALSE)
