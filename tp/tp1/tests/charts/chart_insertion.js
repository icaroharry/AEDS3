google.load('visualization', '1', {packages: ['corechart', 'line']});
google.setOnLoadCallback(drawBasic);

function drawBasic() {

  var data = new google.visualization.DataTable();
  data.addColumn('number', 'X');
  data.addColumn('number', 'Tests');

  data.addRows([ [[7, 0.01],
[8, 0.01],
[9, 0.02],
[10, 0.02],
[11, 0.03],
[12, 0.04],
[13, 0.06],
[14, 0.08],
[15, 0.10],
[16, 0.13],
[17, 0.16],
[18, 0.20],
[19, 0.24],
[20, 0.29],
[21, 0.34]


    ]);


  var options = {
    hAxis: {
      title: 'Entrada(2^x)'
    },
    vAxis: {
      title: 'Tempo(s * 10^-4)'
    }
  };

  var chart = new google.visualization.LineChart(document.getElementById('chart_div'));

  chart.draw(data, options);
}