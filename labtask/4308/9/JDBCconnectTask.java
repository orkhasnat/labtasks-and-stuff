import java.sql.*;

public class JDBCconnectTask {

    public static void main(String[] args) {
        // strings for dbms connection
        String username = "USER1113";
        String passwd = "iutcse";
        String url = "jdbc:oracle:thin:@localhost:1521/orclpdb";
        String query = "select A_ID , AMOUNT , TYPE from TRANSACTIONS";

        // useful variables
        int account, amount, type, totalAccount = 0, cip = 0, vip = 0, ord = 0, unc;
        int[] bal = new int[301];
        int[] accPresent = new int[301];
        int[] total = new int[301];

        try {
            // Register driver class
            Class.forName("oracle.jdbc.driver.OracleDriver");
            // creating a connection object
            Connection con = DriverManager.getConnection(url, username, passwd);
            // creating a statement object
            Statement statement;
            statement = con.createStatement();
            // dbms connection successful
            System.out.println("Connection to database successful");
            // creating the query
            ResultSet result;
            result = statement.executeQuery(query);

            while (result.next()) {
                account = result.getInt(1);
                amount = result.getInt(2);
                type = result.getInt(3);

                if (accPresent[account] == 0) {
                    accPresent[account] = 1;
                    totalAccount++;
                }
                total[account] += amount;
                if (type == 0)
                    bal[account] += amount;
                else
                    bal[account] -= amount;
            }
            // calculating vip cip etc
            for (int i = 1; i <= totalAccount; i++) {
                if (bal[i] > 1000000 && total[i] > 5000000)
                    cip++;
                if (bal[i] > 500000 && bal[i] < 900000 && total[i] > 3500000 && total[i] < 4500000)
                    vip++;
                if (bal[i] < 40000 && total[i] < 3000000)
                    ord++;
            }
            unc = totalAccount - cip - vip - ord;
            // printing to output.txt
            System.out.println("Total Number of Accounts: " + totalAccount);
            System.out.println("CIP count: " + cip);
            System.out.println("VIP count: " + vip);
            System.out.println("Ordinary count: " + ord);
            System.out.println("Uncategorized: " + unc);
            // closing the connection
            con.close();
            statement.close();
            result.close();
        } catch (SQLException e) {
            System.out.println("Cant connect to dbms. Error: " + e);
        } catch (ClassNotFoundException e) {
            System.out.println("Failed to register driver. Error: " + e);
        } catch (Exception e) {
            System.out.println("Unknown Error: " + e);
        }
    }
}