package test;

import java.util.Random;
import java.util.Scanner;

public class homework {

	public void printmenu() {
		System.out.print("=======================\n");
		System.out.print("Enter number to choose the function:\n");
		System.out.print("1. Show the map\n");
		System.out.print("2. Find all available seat\n");
		System.out.print("3. Make a reserve\n");
		System.out.print("4. Exit\n");
		System.out.print("=======================\n");
	}

	public void showMap(char arr[][]) {
		int cnt = 0;

		System.out.print("\t\t1\t2\t3\t4\t5\t6\n");
		System.out.print("-----------------------\n");
		for (int i = 0; i < 6; i++) {
			System.out.print("\t" + (i + 1) + "|");
			for (int j = 0; j < 6; j++) {
				System.out.print("\t" + arr[i][j]);
				if (arr[i][j] == '-') {
					cnt++;
				}
			}
			System.out.print("\n");
		}
		System.out.print("Number of available seats : " + cnt+"\n");
	}

	public void findSeat(char arr[][]) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] == '-') {
					System.out.print("(" + (i + 1) + "," + (j + 1) + ")");
				}
			}
		}
		System.out.print("\n");
	}

	public void makeReserve(char arr[][]) {
		int row;
		int col;

		System.out.print("Input seat row: ");
		Scanner input = new Scanner(System.in);

		row = input.nextInt();

		System.out.print("Input seat column: ");

		col = input.nextInt();

		row = row-1;
		col = col-1;
		
		if (arr[row][col] == '-') {
			arr[row][col] = '*';
			System.out.print("Booked successfully\n");
		} else {
			System.out.print("The seat is not available.\n");
		}
	}

	public void getmenu() {
		char[][] arr = new char[6][6];
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (Math.random() < 0.5) {
					arr[i][j] = '-';
				} else {
					arr[i][j] = '+';
				}
			}
		}
		Scanner input = new Scanner(System.in);

		int menunum;
		for (int i = 0; i < 1;) {
			printmenu();
			System.out.print("Choice: ");
			
			menunum = input.nextInt();
			switch (menunum) {
			case 1:
				showMap(arr);
				break;
			case 2:
				findSeat(arr);
				break;
			case 3:
				makeReserve(arr);
				break;
			case 4:
				System.out.print("Program Exited.");
				i++;
				break;
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		homework app = new homework();
		app.getmenu();
	}

}
