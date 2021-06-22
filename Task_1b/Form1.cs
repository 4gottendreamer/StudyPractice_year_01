using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task_1b
{
	public partial class Form1 : Form
	{
		Graphics g;
		Pen penBlack;
		Pen penRed;
		Point cursor;
		public Form1()
		{
			InitializeComponent();
			g = pictureBox1.CreateGraphics();
			penBlack = new Pen(Color.Black, 1);
			penRed = new Pen(Color.Red, 1);
			g.DrawLine(penBlack,
				new Point(0, ClientSize.Height / 2),
				new Point(ClientSize.Width, ClientSize.Height / 2)
			);
		}

		private void Form1_MouseMove(object sender, MouseEventArgs e)
		{
			cursor = pictureBox1.PointToClient(Cursor.Position);
		}

		private void Form1_Click(object sender, EventArgs e)
		{
			int radius = 4;
			g.DrawEllipse(
				penRed,
				cursor.X - radius / 2,
				cursor.Y - radius / 2,
				radius, radius
			);
		}

		private void buttonDraw_Click(object sender, EventArgs e)
		{
			g.DrawLine(penBlack,
				new Point(0, pictureBox1.Height / 2),
				new Point(pictureBox1.Width, pictureBox1.Height / 2)
			);

			int radius = 6;
			int height = pictureBox1.Height;
			int width = pictureBox1.Width /*- (int)penBlack.Width*/;
			double h = .1f;
			double absRange = 1f;
			double leftBound = -absRange;
			double rightBound = absRange;
			double interval = rightBound - leftBound;
			double phi = leftBound;
			int steps = (int)(interval / h + 1);
			int i = 0;
			Point[] sinePoints = new Point[steps + 1];
			List<Point> sinPointsList = new List<Point>();
			while (phi < rightBound + h / 2) {
				sinePoints[i] = new Point(width / steps * i++, (int)((-height / 2 * Math.Sin(phi)) + height / 2));
				sinPointsList.Add(sinePoints[^1]);
				phi += h;
			}
			g.DrawCurve(penBlack, sinePoints);
			foreach (var item in sinePoints) {
				g.DrawEllipse(penRed, item.X - radius / 2, item.Y - radius / 2, radius, radius);
			}
			dataGridView1.Rows.Clear();
			dataGridView1.Rows.Add(sinePoints.Length);
			for (int j = 0; j < sinePoints.Length; ++j) {
				//dataGridView1.Columns.Add();
				dataGridView1.Rows[j].Cells[0].Value = sinePoints[j].X.ToString();
				dataGridView1.Rows[j].Cells[1].Value = sinePoints[j].Y.ToString();
			}
		}
	}
}
