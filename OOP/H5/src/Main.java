import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.ArrayList;

public class Main{
    private JFrame frame;
    private ArrayList<JLabel> product;
    private double money;
    public Main(){
        frame = new JFrame("Vending Machine");
        product = new ArrayList<JLabel>();
        money = 0;
        frame.setSize(1000, 1000);
        frame.setLayout(new GridBagLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        product.add(new Product("Coke Cola", "../img/cola.jpg", 1.65, 0, 0));
        product.add(new Product("Minute Maid Orange Juice", "../img/orange juice.jpg", 3.5, 0, 3));
        product.add(new Product("Evian Mineral Water", "../img/water.jpg", 2.8, 0, 6));
        product.add(new Product("M&M's Chocolate", "../img/chocolate.jpg", 1.5, 6, 0));
        product.add(new Product("Hershey's Chocolate Bar", "../img/chocolate bar.png", 1.85, 6, 3));
        product.add(new Product("Oreo Cookies", "../img/oreo.jpg", 1, 6, 6));
        product.add(new Product("Doritos Tortilla Chips", "../img/doritos.jpg", 3.25, 12, 0));
        product.add(new Product("Pringles Potato Chips", "../img/pringles.jpg", 3.4, 12, 3));
    }

    public static void main(String[] args){
        Main gui = new Main();
        gui.frame.setVisible(true);
    }

    public class Product extends JLabel implements ActionListener{
        private JLabel name;
        private JLabel image;
        private JLabel quantity;
        private JLabel price;
        private JButton select;
        private JButton cancel;
        private int number;
        private int row;
        private int col;

        public Product(String name, String image, double price, int row, int col){
            this.name = new JLabel(name);
            this.image = new JLabel(new ImageIcon(image));
            this.select = new JButton("+");
            this.cancel = new JButton("-");
            this.quantity = new JLabel("0");
            this.number = 0;
            this.price = new JLabel("Price: " + price, SwingConstants.CENTER);
            this.row = row;
            this.col = col;
            this.select.addActionListener(this);
            this.cancel.addActionListener(this);
            setGrid(row, col);
        }

        public void actionPerformed(ActionEvent e){
            if(e.getSource() == this.select){
                this.number++;
                this.quantity.setText(Integer.toString(number));
            }
            else if(e.getSource() == this.cancel){
                if(number > 0){
                    this.number--;
                    this.quantity.setText(Integer.toString(number));
                }
            }
        }

        public void setGrid(int row, int col){
            //gridx = col, gridy = row;
            GridBagConstraints c = new GridBagConstraints();
            c.gridx = col;
            c.gridy = row;
            c.gridwidth = 3;
            c.gridheight = 1;
            c.insets = new Insets(10, 10, 10, 10);
            c.fill = GridBagConstraints.HORIZONTAL;
            frame.add(name, c);

            c.gridy = GridBagConstraints.RELATIVE;
            c.fill = GridBagConstraints.NONE;
            c.gridheight = 3;
            frame.add(image, c);

            c.gridx = col;
            c.gridwidth = 3;
            c.gridheight = 1;
            c.fill = GridBagConstraints.HORIZONTAL;
            frame.add(price, c);

            c.gridwidth = 1;
            c.gridheight = 1;
            c.fill = GridBagConstraints.NONE;
            frame.add(cancel, c);

            c.gridx = col + 1;
            frame.add(quantity, c);

            c.gridx = col + 2;
            frame.add(select, c);
        }
    }
}
