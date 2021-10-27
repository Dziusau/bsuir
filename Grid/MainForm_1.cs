using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using ZedGraph;

namespace Grid
{
    public partial class MainForm_1 : Form
    {
        public MainForm_1(double[][] Fi)
        {
            InitializeComponent();

            DrawGraph(Fi);
        }

        private void DrawGraph(double[][] Fi)
        {
            GraphPane pane = zedGraph.GraphPane;

            pane.CurveList.Clear();
            pane.Title.Text = "Кол-во итераций / Релаксация";

            PointPairList list = new PointPairList();

            for (int i = 0; i < Fi[0].Length; i++)
            {
                list.Add(Fi[0][i], Fi[1][i]);

            }

            LineItem myCurve = pane.AddCurve("f(x)", list, Color.Blue, SymbolType.None);

            // !!!
            // Включаем отображение сетки напротив крупных рисок по оси X
            pane.XAxis.MajorGrid.IsVisible = true;

            // Задаем вид пунктирной линии для крупных рисок по оси X:
            // Длина штрихов равна 10 пикселям, ... 
            pane.XAxis.MajorGrid.DashOn = 10;

            // затем 5 пикселей - пропуск
            pane.XAxis.MajorGrid.DashOff = 5;


            // Включаем отображение сетки напротив крупных рисок по оси Y
            pane.YAxis.MajorGrid.IsVisible = true;

            // Аналогично задаем вид пунктирной линии для крупных рисок по оси Y
            pane.YAxis.MajorGrid.DashOn = 10;
            pane.YAxis.MajorGrid.DashOff = 5;


            // Включаем отображение сетки напротив мелких рисок по оси X
            pane.YAxis.MinorGrid.IsVisible = true;

            // Задаем вид пунктирной линии для крупных рисок по оси Y: 
            // Длина штрихов равна одному пикселю, ... 
            pane.YAxis.MinorGrid.DashOn = 1;

            // затем 2 пикселя - пропуск
            pane.YAxis.MinorGrid.DashOff = 2;

            // Включаем отображение сетки напротив мелких рисок по оси Y
            pane.XAxis.MinorGrid.IsVisible = true;

            // Аналогично задаем вид пунктирной линии для крупных рисок по оси Y
            pane.XAxis.MinorGrid.DashOn = 1;
            pane.XAxis.MinorGrid.DashOff = 2;

            zedGraph.AxisChange();

            zedGraph.Invalidate();
        }

        private void zedGraph_Load(object sender, EventArgs e)
        {

        }
    }
}