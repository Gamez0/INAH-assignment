package project;

import java.awt.EventQueue;

import javax.swing.JFrame;
import java.awt.GridBagLayout;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.GridBagConstraints;
import javax.swing.JTextField;
import java.awt.Insets;
import javax.swing.JPanel;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class ArrayTestApp {

	private JFrame frmArrayTestApp;
	private JLabel lblNewLabel;
	private JTextField txtInput;
	private JLabel lblArray;
	private JPanel panel;
	private JLabel lblNewLabel_2;
	private JTextField testIndex;
	private JLabel lblNewLabel_3;
	private JTextField textNumber;

	private int array[];
	private int index;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ArrayTestApp window = new ArrayTestApp();
					window.frmArrayTestApp.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public ArrayTestApp() {
		initialize();
		array = new int[10];
		index = 0;
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmArrayTestApp = new JFrame();
		frmArrayTestApp.setTitle("Array Test App");
		frmArrayTestApp.setBounds(100, 100, 442, 211);
		frmArrayTestApp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		GridBagLayout gridBagLayout = new GridBagLayout();
		gridBagLayout.columnWidths = new int[] {0, 0, 30};
		gridBagLayout.rowHeights = new int[] {0, 0};
		gridBagLayout.columnWeights = new double[]{0.0, 0.0, 0.0};
		gridBagLayout.rowWeights = new double[]{0.0, 0.0, 0.0};
		frmArrayTestApp.getContentPane().setLayout(gridBagLayout);
		
		lblNewLabel = new JLabel("input number");
		GridBagConstraints gbc_lblNewLabel = new GridBagConstraints();
		gbc_lblNewLabel.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel.gridx = 0;
		gbc_lblNewLabel.gridy = 0;
		frmArrayTestApp.getContentPane().add(lblNewLabel, gbc_lblNewLabel);
		
		txtInput = new JTextField();
		txtInput.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
				try {
				inputNumber();
				
				String str ="";
				for(int i=0;i<index;i++){
					str = str + " "+ array[i];
				}
				str = "a = [" + str.trim() + "]";
				lblArray.setText(str);
				}
				catch (NumberFormatException nex){
					JOptionPane.showMessageDialog(null, "죽음은 힘들지도 안 힘들지도 않아");
				}
				catch (DuplicateException e1){
					JOptionPane.showMessageDialog(null, e1.getMessage());
					
				}
				catch (Exception ex){
					JOptionPane.showMessageDialog(null, ex.toString(),"이상해",JOptionPane.ERROR_MESSAGE);
				} finally {
					txtInput.setText("");
				}
			}
		});
		GridBagConstraints gbc_txtInput = new GridBagConstraints();
		gbc_txtInput.fill = GridBagConstraints.HORIZONTAL;
		gbc_txtInput.insets = new Insets(0, 0, 5, 0);
		gbc_txtInput.gridx = 1;
		gbc_txtInput.gridy = 0;
		frmArrayTestApp.getContentPane().add(txtInput, gbc_txtInput);
		txtInput.setColumns(10);
		
		lblArray = new JLabel("a=[ ]");
		GridBagConstraints gbc_lblArray = new GridBagConstraints();
		gbc_lblArray.insets = new Insets(0, 0, 0, 5);
		gbc_lblArray.gridx = 1;
		gbc_lblArray.gridy = 1;
		frmArrayTestApp.getContentPane().add(lblArray, gbc_lblArray);
		
		panel = new JPanel();
		GridBagConstraints gbc_panel = new GridBagConstraints();
		gbc_panel.fill = GridBagConstraints.BOTH;
		gbc_panel.gridx = 1;
		gbc_panel.gridy = 2;
		frmArrayTestApp.getContentPane().add(panel, gbc_panel);
		
		lblNewLabel_2 = new JLabel("a=[");
		panel.add(lblNewLabel_2);
		
		testIndex = new JTextField();
		panel.add(testIndex);
		testIndex.setColumns(10);
		
		lblNewLabel_3 = new JLabel("] =");
		panel.add(lblNewLabel_3);
		
		textNumber = new JTextField();
		panel.add(textNumber);
		textNumber.setColumns(10);
	}
	public void inputNumber() throws DuplicateException{
		// read the input number
		int num = Integer.parseInt(txtInput.getText());
		
		// check the number
		boolean found = false;
		for(int i=0;i<index; i++){
			if(array[i] == num){
				throw new DuplicateException();
			}
		}
		
		// insert num in the array
		array[index] = num;
		index++;
	}
}
