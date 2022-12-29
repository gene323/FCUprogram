import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.ArrayList;

public class Main implements ActionListener{
    private static final int TIME_LEAVE = 2000;
    private JFrame frame;
    private ArrayList<Product> product;
    private JLabel moneyLabel;
    private double money;
    private JButton btn1;
    private JButton btn2;
    private JButton btn3;
    private JButton btn4;

    public Main(){
        frame = new JFrame("Vending Machine");
        product = new ArrayList<Product>();
        moneyLabel = new JLabel("Money: 0", SwingConstants.CENTER);
        btn1 = new JButton("1");
        btn2 = new JButton("5");
        btn3 = new JButton("10");
        btn4 = new JButton("15");
        btn1.addActionListener(this);
        btn2.addActionListener(this);
        btn3.addActionListener(this);
        btn4.addActionListener(this);
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

        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(10, 10, 10, 10);
        c.gridx = GridBagConstraints.RELATIVE;
        c.gridy = 18;
        c.gridwidth = 3;
        c.gridheight = 1;
        c.fill = GridBagConstraints.HORIZONTAL;
        frame.add(btn1, c);
        frame.add(btn2, c);
        
        c.gridy = 19;
        frame.add(btn3, c);
        frame.add(btn4, c);

        c.gridwidth = 3;
        c.gridheight = 2;
        c.gridy = 18;
        c.fill = GridBagConstraints.BOTH;
        moneyLabel.setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
        frame.add(moneyLabel, c);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource() == btn1){
            money += 1;
        }
        else if(e.getSource() == btn2){
            money += 5;
        }
        else if(e.getSource() == btn3){
            money += 10;
        }
        else if(e.getSource() == btn4){
            money += 15;
        }
        moneyLabel.setText("Money: " + money);
        product.forEach((p) -> {
            p.enableBuy();
        });
    }

    public static void main(String[] args){
        Main gui = new Main();
        gui.frame.setVisible(true);
    }

    public class Product implements ActionListener{
        private JLabel name;
        private JLabel image;
        private JLabel priceLabel;
        private JButton select;
        private double priceNum;
        private int row;
        private int col;

        public Product(String name, String image, double price, int row, int col){
            this.name = new JLabel(name);
            this.image = new JLabel(new ImageIcon(image));
            this.select = new JButton("buy");
            this.priceLabel = new JLabel("Price: " + price, SwingConstants.CENTER);
            this.priceNum = price;
            this.row = row;
            this.col = col;
            this.select.addActionListener(this);
            this.select.setEnabled(false);
            setGrid(row, col);
        }

        public void actionPerformed(ActionEvent e){
            money -= priceNum;
            moneyLabel.setText("Money: " + money);
            if(money < this.priceNum)
                this.select.setEnabled(false);
            product.forEach((p) -> {
                if(p.priceNum > money)
                    p.select.setEnabled(false);
            });
        }

        public void enableBuy(){
            if(money >= priceNum)
                this.select.setEnabled(true);
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
            c.gridheight = 1;
            c.fill = GridBagConstraints.HORIZONTAL;
            frame.add(priceLabel, c);
            frame.add(select, c);
        }
    }
}
