import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class HelloWorld {
	public static void main(String [] args) {
		// Create the window
		JFrame frame = new JFrame();
		frame.setTitle("Hello World!");
		frame.setSize(300,120);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// Create the label
		JLabel label = new JLabel("Hello world");
		label.setForeground(Color.RED);
		label.setBackground(Color.DARK_GRAY);
		label.setOpaque(true);
		// label.setText("Hello world");
		frame.add(label);


	}
}
