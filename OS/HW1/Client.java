import java.io.*;
import java.net.*;
import java.util.*;

public class Client {
    public static void main(String[] args) {
        final String SERVER_IP = "127.0.0.1"; // Server's IP address
        final int SERVER_PORT = 5050; // Server's port number

        try{
            Socket socket = new Socket(SERVER_IP, SERVER_PORT);
            OutputStream outputStream = socket.getOutputStream();

            System.out.println("Connected to the Server. enter exit to close program");

            // Send a message to the server
            String message = "";
            Scanner sc = new Scanner(System.in);
            while(true){
                System.out.print("To Server: ");
                message = sc.nextLine();
                byte[] messageBytes = message.getBytes();
                outputStream.write(messageBytes);
                outputStream.flush();

                if(message.equals("exit")) break;
            }


            sc.close();

        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}

