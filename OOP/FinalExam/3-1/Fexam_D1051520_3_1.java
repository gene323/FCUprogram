import java.util.Scanner;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.File;

public class Fexam_D1051520_3_1 {
    private static final int N = 30;
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		String path = new File("").getAbsolutePath();// Path of the image files.
		String sourName; // Source image file name.
		String destName; // Copied image file name.
		
		System.out.print("Enter the source image file name: ");
        sourName = in.nextLine();
		
		System.out.print("Enter the copied image file name: ");
        destName = in.nextLine();
		
		BitmapImage image = new BitmapImage(path + '/' + sourName); // Create a bitmap image object.
		
		try {
			// Read the source image.
			// Print the file header and image information of the source image. 
            System.out.println("=".repeat(N));
            image.readImage();
            image.printImage();
			
			// Rename the image to the copied image file name.                                                                            
			// Write the copied image.
			// Print the file header and image information of the copied image.
            System.out.println("=".repeat(N));
            image.renameImage(path + '/' + destName);
            image.writeImage();
            image.printImage();
		}
		catch (Exception ex) { 
			// Print the stack trace, if exception occurs.
            System.out.println(ex);
		}
		// Close the standard input stream.
        in.close();
	}
}
