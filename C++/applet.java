/* Java to program to test an Applet
Written by Arpit Kumar Singh(13/CS/31)
*/
import java.awt.FlowLayout;
import javax.swing.*;
import javax.swing.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
public class Name_S extends  Applet implements ActionListener{
	 TextField input,output,output1;
	   Label label1,label2;
	   Button b1;
	   JLabel lbl;
	   int num, sum = 0;
	   String name;
	   public void init(){
	      label1 = new Label("please enter Name ");
	      add(label1);
	      label1.setBackground(Color.yellow);
	      label1.setForeground(Color.magenta);
	      input = new TextField(20);
	      add(input);
	      label2 = new Label("first Name: ");
	      add(label2);
	      label2.setBackground(Color.yellow);
	      label2.setForeground(Color.magenta);
	      output = new TextField(10);
	      add(output);
	      label2 = new Label("last  Name: ");
	      add(label2);
	      label2.setBackground(Color.yellow);
	      label2.setForeground(Color.magenta);
	      output1 = new TextField(10);
	      add(output1);
	      b1 = new Button("Validate");
	      add(b1);
	      b1.addActionListener(this);
	      lbl = new JLabel("Swing Applet Example. ");
	      add(lbl);
	      setBackground(Color.yellow);
	   }
	   public void actionPerformed(ActionEvent ae){
	     
		   String first,last;
		   try{
	         name = (input.getText());
	         String[] s = name.split(" ");
	         input.setText(name);
	         first=name.substring(name.lastIndexOf(' ')+1);
	         
	         output1.setText(s[1]);
	         last=name.substring(0,name.indexOf(' '));
	         output.setText(s[0]);
	       
	         
	        
	      }
	      catch(NumberFormatException e){
	         lbl.setForeground(Color.red);
	         lbl.setText("Invalid Entry!");
	      }
	   }  
	
}

