import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
public class ConvertFrame extends JFrame {

	private JLabel lblDistance;
	private JTextField txtInputKm;
	private JButton btnConvert;
	private JTextField txtOutputMile;
	
	class ButtonListener implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent arg0) {
			// TODO Auto-generated method stub
			double km = Double.parseDouble(txtInputKm.getText());
			double mile = km * 0.621;
			txtOutputMile.setText(""+mile);
		}
		
	}
	
	public ConvertFrame() {
		super("Converter");
		lblDistance = new JLabel("Distance in km");
		txtInputKm = new JTextField(1);
		btnConvert = new JButton("Calculate");
		txtOutputMile = new JTextField();
		
		txtOutputMile.setEditable(false);
		btnConvert.addActionListener(new ButtonListener());
		
		this.setLayout(new GridLayout(2,2));
		this.add(lblDistance);
		this.add(txtInputKm);
		this.add(btnConvert);
		this.add(txtOutputMile);
		
		this.setSize(300,120);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
