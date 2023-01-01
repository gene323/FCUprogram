import java.util.Scanner;
import java.io.File;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;

public class Fexam_D1051520_3_2 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String sourName; // Source image file name.
		String destName; // Flip and merge image file name.

		System.out.print("Enter the source image file name: ");
        sourName = in.nextLine();
		
		System.out.print("Enter the flip and merge image file name: ");
        destName = in.nextLine();

        BufferedImage sourImg = null;
		
        try{
            sourImg = ImageIO.read(new File(sourName));
        } catch(Exception ex){
            System.out.println(ex);
        }

        int width = sourImg.getWidth();
        int height = sourImg.getHeight();
        BufferedImage mirrorImg = new BufferedImage(width * 2, height, BufferedImage.TYPE_INT_ARGB);
        for(int i=0; i<height; i++){
            for(int lx=0, rx=width * 2 - 1; lx < width; lx++, rx--){
                int p = sourImg.getRGB(lx, i);
                mirrorImg.setRGB(lx, i, p);
                mirrorImg.setRGB(rx, i, p);
            }
        }

		try {
            File f = new File(destName);
            ImageIO.write(mirrorImg, "png", f);
		} catch (Exception ex) {
            System.out.println(ex);
		}
		// Close the standard input stream.
        in.close();
	}
}
