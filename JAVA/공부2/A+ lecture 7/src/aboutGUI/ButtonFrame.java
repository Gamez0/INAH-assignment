package aboutGUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class ButtonFrame extends JFrame {
	private JButton plainJButton;
	private JButton fancyJButton;
	public ButtonFrame() {
		super("Testing Buttons");
		setLayout(new FlowLayout());
		
		plainJButton = new JButton("Plain Button");
		add(plainJButton);
		
		
		ButtonHandler handler = new ButtonHandler();
		fancyJButton.addActionListener(handler);
		plainJButton.addActionListener(handler);
	}
	
	private class ButtonHandler implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			 JOptionPane.showMessageDialog( ButtonFrame.this,String.format("You pressed: %s", event.getActionCommand() ) );
		}
	}
	
	
}
