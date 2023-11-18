if(!require("BiocManager", quietly = TRUE))
install.packages("BiocManager")

BiocManager::install(version = "3.17")
BiocManager::install("TCGAbiolinks")

download_function <- function(project_id){
  dwn_dir <- "D:/bio/GDCdata"
  project_id <- paste("TCGA",project_id, sep = '-') 
  projects<-c(project_id)
  query <- GDCquery(project = projects,
                    data.category = "Transcriptome Profiling",
                    data.type = "Gene Expression Quantification",
                    workflow.type = "STAR - Counts")
  GDCdownload(query, method="api",dir = dwn_dir)
  GDCprepare(query = query, summarizedExperiment = TRUE,,dir = dwn_dir)
}

library(TCGAbiolinks)
library(SummarizedExperiment)


project_ids <- c("UCEC", "KICH", "LIHC", "ESCA")


se_list <- list()

for (project_id in project_ids) {
  
  se <- download_function(project_id)
  
  se_list[[project_id]] <- se
}

# storing tumor & normal data

normal_data_list <- list()
tumor_data_list <- list()

normal_sample_counts <- list()
tumor_sample_counts <- list()

se_mrna_list <- list()

for (project_id in project_ids) {
  
  se <- se_list[[project_id]]
  se_mrna <- se[se$gene_type == "protein_coding", ]
  se_mrna_list[[project_id]] <- se_mrna
  
  
  normal_samples <- colData(se_mrna)$sample_type == "Solid Tissue Normal"
  normal_sample_counts[[project_id]] <- sum(normal_samples)
  normal_df <- assays(se)$fpkm_unstrand[, normal_samples]
  normal_data_list[[project_id]] <- normal_df
  
  
  
  tumor_samples <- colData(se_mrna)$sample_type == "Primary Tumor"
  tumor_sample_counts[[project_id]] <- sum(tumor_samples)
  tumor_df <- assays(se)$fpkm_unstrand[, tumor_samples]
  tumor_data_list[[project_id]] <- tumor_df
}

# merging them

all_normal_data <- do.call(cbind, normal_data_list)
all_tumor_data <- do.call(cbind, tumor_data_list)


# csvs 
labels <- c(rep(0, ncol(all_normal_data)), rep(1, ncol(tumor_data_list[['UCEC']]))
            ,rep(2, ncol(tumor_data_list[['KICH']])), rep(3, ncol(tumor_data_list[['LIHC']])),
            rep(4, ncol(tumor_data_list[['ESCA']])))

X <- cbind(all_normal_data, tumor_data_list[['UCEC']], tumor_data_list[['KICH']], 
           tumor_data_list[['LIHC']], tumor_data_list[['ESCA']])

X <- t(X)

X <- log10(X + 1)

write.table(labels,"labels.csv",sep=",",col.names=FALSE,row.names=FALSE)
write.csv(X,"data.csv")


# imp value
for (project_id in project_ids) {
  
  print('--------------------------')
  print(project_id)
  
  print(ncol(assays(se_mrna_list[[project_id]])$fpkm_unstrand)) #feature/gene count
  
  print(table(colData(se_mrna_list[[project_id]])$sample_type)) #sample type
  
  
  print(nrow(normal_data_list[[project_id]])) #feature/gene
  print(nrow(tumor_data_list[[project_id]]))
  print(normal_sample_counts[[project_id]]) #sample
  print(tumor_sample_counts[[project_id]])
  
  print('--------------------------')
}
