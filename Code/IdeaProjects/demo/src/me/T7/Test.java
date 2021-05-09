package me.T7;

import javax.swing.*;
import java.awt.*;

/**
 * @author liukanglai
 * @date 5/9/21 - 5:28 PM
 */
public class Test {

    static int[] length = new int[]{0, 0, 0};
    static class SomeOneRun extends Thread {
        String player;
        int who = 0;
        JPanel panel;

        SomeOneRun(int who, String player, JPanel panel) {
            this.who = who;
            this.player = player;
            this.panel = panel;
        }

        @Override
        public void run() {
            //MyPanel myPanel = new MyPanel();
            //panel.add(myPanel);
            for (int i = 0; length[0] < 1000 && length[1] < 1000 && length[2] < 1000; i++) {
                length[who] += (int) (Math.random() * 21);
                System.out.println(player + "run, the length1 is: " + length[who]);
            }
        }

        class MyPanel extends JPanel {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.red);
                g.fillRect(20, 150, length[who] +100, 35);
            }
        }
    }

    public static void main(String[] args) {
        String player0 = "甲同学";
        String player1 = "乙同学";
        String player2 = "ͬ丙同学";


        JFrame frame = new JFrame("赛跑");
        frame.setSize(500, 600);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(3);

        JPanel big_panel = new JPanel(new GridLayout(5, 1));
        JPanel in_panel0 = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JPanel in_panel1 = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JPanel in_panel2 = new JPanel(new FlowLayout(FlowLayout.LEFT));
        big_panel.add(in_panel0);
        big_panel.add(in_panel1);
        big_panel.add(in_panel2);

        Font font = new Font(null, Font.PLAIN, 15);
        JLabel label0 = new JLabel(player0);
        label0.setFont(font);
        in_panel0.add(label0);

        JLabel label1 = new JLabel(player1);
        label1.setFont(font);
        in_panel1.add(label1);

        JLabel label2 = new JLabel(player2);
        label2.setFont(font);
        in_panel2.add(label2);
        MyPanel myPanel = new MyPanel();
        //in_panel0.add(myPanel);
        big_panel.add(myPanel);

        /*
        SomeOneRun run0 = new SomeOneRun(0, player0, in_panel0);
        SomeOneRun run1 = new SomeOneRun(1, player1, in_panel1);
        SomeOneRun run2 = new SomeOneRun(2, player2, in_panel2);

        run0.start();
        run1.start();
        run2.start();

         */

        frame.setContentPane(big_panel);
        frame.setVisible(true);
    }
}

class MyPanel extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.red);
        g.fillRect(10, 0, 10, 35);
    }
}