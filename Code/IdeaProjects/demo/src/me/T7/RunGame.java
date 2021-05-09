package me.T7;

import javax.swing.*;
import java.awt.*;

/**
 * @author liukanglai
 * @date 5/9/21 - 9:45 AM
 */
public class RunGame {

    static int[] length = new int[]{0, 0, 0};
    static class SomeOneRun extends Thread {
        String player;
        int who = 0;
        JPanel panel;
        Graphics g;

        SomeOneRun(int who, String player, JPanel panel) {
            this.who = who;
            this.player = player;
            this.panel = panel;
            Font font = new Font(null, Font.PLAIN, 15);
            JLabel label0 = new JLabel(player);
            label0.setFont(font);
            panel.add(label0);
            g = panel.getGraphics();
        }

        @Override
        public void run() {
            for (int i = 0; length[0] < 1000 && length[1] < 1000 && length[2] < 1000; i++) {
                length[who] += (int) (Math.random() * 21);
                System.out.println(player + "run, the length1 is: " + length[who]);
                try {
                    Thread.sleep(100);
                }
                catch (InterruptedException e){
                }
                g = panel.getGraphics();
                g.fillRect(20, 0, length[who]/3, 35);
            }
        }

        class MyPanel extends JPanel {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
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

        JPanel big_panel = new JPanel(new GridLayout(3, 1));
        JPanel in_panel0 = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JPanel in_panel1 = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JPanel in_panel2 = new JPanel(new FlowLayout(FlowLayout.LEFT));

        SomeOneRun run0 = new SomeOneRun(0, player0, big_panel);
        SomeOneRun run1 = new SomeOneRun(1, player1, big_panel);
        SomeOneRun run2 = new SomeOneRun(2, player2, big_panel);

        run0.start();
        run1.start();
        run2.start();

        frame.setContentPane(big_panel);
        frame.setVisible(true);
    }
}