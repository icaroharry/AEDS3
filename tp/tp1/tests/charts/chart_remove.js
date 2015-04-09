google.load('visualization', '1', {packages: ['corechart', 'line']});
google.setOnLoadCallback(drawBasic);

function drawBasic() {

  var data = new google.visualization.DataTable();
  data.addColumn('number', 'X');
  data.addColumn('number', 'Tests');

  data.addRows([
    [7, 0.000101],
    [8, 0.000320],
    [9, 0.000663],
    [7, 0.000097],
    [8, 0.000314],
    [9, 0.000638],
    [10, 0.001208],
    [11, 0.002304],
    [12, 0.004821],
    [13, 0.010231],
    [14, 0.023026],
    [15, 0.051513],
    [16, 0.114946],
    [17, 0.253417],
    [18, 0.552824],
    [19, 1.205567],
    [20, 2.563146],
    [21, 5.452899]


    ]);


  var options = {
    hAxis: {
      title: 'Entrada(2^x)'
    },
    vAxis: {
      title: 'Tempo(s)'
    }
  };

  var chart = new google.visualization.LineChart(document.getElementById('chart_div'));

  chart.draw(data, options);
}