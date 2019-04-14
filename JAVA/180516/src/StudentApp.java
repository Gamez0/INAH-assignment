import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JMenu;
import javax.swing.JTabbedPane;
import java.awt.BorderLayout;
import javax.swing.JPanel;
import java.awt.GridLayout;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextArea;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.awt.event.ActionEvent;

public class StudentApp implements ActionListener {

	private JFrame frmStudentInfoApp;
	private JMenuBar menuBar;
	private JMenuItem mniClear;
	private JMenu mnNewMenu;
	private JMenuItem mniOpen;
	private JMenuItem mniSave;
	private JMenuItem mniClose;
	private JTabbedPane tabbedPane;
	private JPanel panel;
	private JPanel panel_1;
	private JLabel lblNewLabel;
	private JTextField txtid;
	private JLabel lblNewLabel_1;
	private JTextField txtName;
	private JLabel lblNewLabel_2;
	private JComboBox cbGender;
	private JTextArea textArea;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					StudentApp window = new StudentApp();
					window.frmStudentInfoApp.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public StudentApp() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmStudentInfoApp = new JFrame();
		frmStudentInfoApp.setTitle("Student info App");
		frmStudentInfoApp.setBounds(100, 100, 450, 300);
		frmStudentInfoApp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		menuBar = new JMenuBar();
		frmStudentInfoApp.setJMenuBar(menuBar);

		mnNewMenu = new JMenu("File");
		menuBar.add(mnNewMenu);

		mniOpen = new JMenuItem("Open");
		mniOpen.addActionListener(this);
		mnNewMenu.add(mniOpen);

		mniSave = new JMenuItem("Save");
		mniSave.addActionListener(this);
		mnNewMenu.add(mniSave);

		mniClose = new JMenuItem("Close");
		mniClose.addActionListener(this);
		mnNewMenu.add(mniClose);

		mniClear = new JMenuItem("Clear");
		mniClear.addActionListener(this);
		menuBar.add(mniClear);

		tabbedPane = new JTabbedPane(JTabbedPane.BOTTOM);
		frmStudentInfoApp.getContentPane().add(tabbedPane, BorderLayout.CENTER);

		panel = new JPanel();
		panel.setBorder(new EmptyBorder(10, 10, 10, 10));
		tabbedPane.addTab("Info", null, panel, null);
		panel.setLayout(new GridLayout(3, 2, 0, 0));

		lblNewLabel_1 = new JLabel("ID");
		panel.add(lblNewLabel_1);

		txtid = new JTextField();
		panel.add(txtid);
		txtid.setColumns(10);

		lblNewLabel_2 = new JLabel("Name");
		panel.add(lblNewLabel_2);

		txtName = new JTextField();
		panel.add(txtName);
		txtName.setColumns(10);

		lblNewLabel = new JLabel("Gender");
		panel.add(lblNewLabel);

		cbGender = new JComboBox();
		panel.add(cbGender);

		panel_1 = new JPanel();
		tabbedPane.addTab("Others", null, panel_1, null);
		panel_1.setLayout(new BorderLayout(0, 0));

		textArea = new JTextArea();
		panel_1.add(textArea, BorderLayout.CENTER);
	}

	public void actionPerformed(ActionEvent e) {
		JFileChooser fc = new JFileChooser();
		// Check the source of the event
		if (e.getSource() == mniOpen) {
			textArea.setText("");
			int ret = fc.showOpenDialog(frmStudentInfoApp);
			// if user click ok
			if (ret == JFileChooser.APPROVE_OPTION) {

				try {
					FileReader fr = new FileReader(fc.getSelectedFile().getAbsolutePath());
					BufferedReader br = new BufferedReader(fr);
					String sCurrentLine;
					// read until the end of file
					while ((sCurrentLine = br.readLine()) != null) {
						// System.out.println(sCurrentLine);
						textArea.append(sCurrentLine + "\n");
					}
					br.close();
				} catch (Exception ex) {

				}
			}
		} else if (e.getSource() == mniClose) {
			frmStudentInfoApp.dispose();
		} else if (e.getSource() == mniClear) {
			Student std1 = new Student("버림받은자",12141556,23);
			try{
				FileOutputStream fo = new FileOutputStream("student.data");
				ObjectOutputStream out = new ObjectOutputStream(fo);
				// make sure the object is serializable
				out.writeObject(std1);
				out.close();
			}catch (IOException e1){
				
			}

			textArea.setText("");
		} else if (e.getSource() == mniSave) {
			int rst = fc.showSaveDialog(frmStudentInfoApp);
			// if user click ok
			if (rst == JFileChooser.APPROVE_OPTION) {

				try {
					FileWriter fw = new FileWriter(fc.getSelectedFile().getAbsolutePath());
					BufferedWriter bw = new BufferedWriter(fw);
					bw.write(textArea.getText());
					bw.flush();
					bw.close();
				} catch (Exception ex) {
				}
			}
		}
	}

}
