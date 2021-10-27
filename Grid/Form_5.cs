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
    public partial class Form_5 : Form
    {
        public Form_5(double[,] f, List<Dictionary<double, int>> list_dict)
        {
            InitializeComponent();

            DrawGraph(f, list_dict);
        }

        private void DrawGraph(double[,] f, List<Dictionary<double, int>> list_dict)
        {
            GraphPane pane = zedGraph.GraphPane;

            pane.CurveList.Clear();
            pane.Title.Text = "MDP";

            PointPairList list_fun = new PointPairList();
            List<PointPairList> list_d = new List<PointPairList>();

            for (int i = 0; i < f.Length / 2; i++)
            {
                list_fun.Add(f[0, i], f[1, i]);
            }

            foreach (var d in list_dict)
            {
                PointPairList list = new PointPairList();
                foreach (var pair in d)
                {
                    list.Add(pair.Key, pair.Value);
                    list_d.Add(list);
                }
            }

            LineItem funCurve = pane.AddCurve("f(x)", list_fun, Color.Blue, SymbolType.None);
            foreach (var l in list_d)
            {
                LineItem dCurve = pane.AddCurve("it(eps)", l, Color.Red, SymbolType.None);
            }

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
