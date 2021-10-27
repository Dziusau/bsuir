using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ZedGraph;

namespace Grid
{
    public partial class Form_3 : Form
    {
        public Form_3(double[,] f, double[] d1, double[] d2, double[] d1t, double[] d2t, double[] delta_1, double[] delta_2)
        {
            InitializeComponent();

            DrawGraph(f, d1, d2, d1t, d2t, delta_1, delta_2);
        }

        private void DrawGraph(double[,] f, double[] d1, double[] d2, double[] d1t, double[] d2t, double[] delta_1, double[] delta_2)
        {
            GraphPane pane = zedGraph.GraphPane;

            pane.CurveList.Clear();
            pane.Title.Text = "Gausse 3";

            PointPairList list_fun = new PointPairList();
            PointPairList list_d1 = new PointPairList();
            PointPairList list_d2 = new PointPairList();
            PointPairList list_d1t = new PointPairList();
            PointPairList list_d2t = new PointPairList();
            PointPairList list_delta_1 = new PointPairList();
            PointPairList list_delta_2 = new PointPairList();

            for (int i = 0; i < f.Length / 2; i++)
            {
                list_fun.Add(f[0, i], f[1, i]);
                list_d1.Add(f[0, i], d1[i]);
                list_d2.Add(f[0, i], d2[i]);
                list_d1t.Add(f[0, i], d1t[i]);
                list_d2t.Add(f[0, i], d2t[i]);
                list_delta_1.Add(f[0, i], delta_1[i]);
                list_delta_2.Add(f[0, i], delta_2[i]);
            }

            LineItem funCurve = pane.AddCurve("f(x)", list_fun, Color.Blue, SymbolType.None);
            LineItem d1Curve = pane.AddCurve("d1(x)", list_d1, Color.Red, SymbolType.None);
            LineItem d2Curve = pane.AddCurve("d2(x)", list_d2, Color.Cyan, SymbolType.None);
            LineItem d1tCurve = pane.AddCurve("d1t(x)", list_d1t, Color.Green, SymbolType.None);
            LineItem d2tCurve = pane.AddCurve("d2t(x)", list_d2t, Color.Black, SymbolType.None);
            LineItem delta1Curve = pane.AddCurve("delta_1(x)", list_delta_1, Color.Orange, SymbolType.None);
            LineItem delta2Curve = pane.AddCurve("delta_2(x)", list_delta_2, Color.Brown, SymbolType.None);


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
