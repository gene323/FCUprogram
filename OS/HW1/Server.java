import java.io.*;
import java.net.*;

public class Server{
    public static void main(String[] args){
        final int PORT = 5050;

        try{
            ServerSocket serverSocket = new ServerSocket(PORT);
            System.out.println("Server is listening on port: " + PORT);

            while(true){
                try{
                    Socket clientSocket = serverSocket.accept();
                    InputStream inputStream = clientSocket.getInputStream();
                    OutputStream outputStream = clientSocket.getOutputStream();

                    System.out.println("Client connected: " + clientSocket.getInetAddress());

                    byte[] buf = new byte[1024];
                    int bytesRead;

                    while((bytesRead = inputStream.read(buf)) != -1){
                        String clientData = new String(buf, 0, bytesRead);
                        System.out.println(clientData);

                        // Echo the data back to the client
                        outputStream.write(buf, 0, bytesRead);
                        outputStream.flush();
                    }

                    System.out.println("Client diconnected: " + clientSocket.getInetAddress());
                    break;

                } catch(IOException e) {
                    System.err.println("Error handling client: " + e.getMessage());
                }

            }

        } catch(IOException e) {
            System.err.println("Could not listen on port: " + PORT);
            System.exit(1);
        }
    }
}
