readtable function for xlsx 

xticks 

%clear 

close all 

%load data.xlsx -xlsx 

%x = table2cell(data(:,1)); 

%y = data(:,2); 

score0 = {3, 2}; 

score1 = {1, 2}; 

score2 = {0, 2}; 

figurefill([-0.5 0.5 0.5 -0.5], [5 5 0 0], 'g') 

hold on 

fill([0.5 1.5 1.5 0.5], [3 3 0 0], 'y') 

fill([1.5 2.5 2.5 1.5], [2 2 0 0], 'r') 

xlabel('Stimulus Level') 

ylabel('Correct') 

X = [0, 1, 2]; 

Y = [2.5 1.5 1]; %means of each score 

bar(X, Y, 'w') 

er = errorbar(X,Y,[0.5, 0.5, 1], 'LineWidth',2); 

er.Color = [0 0 0];  

er.LineStyle = 'none'; 

axis([-1 3 0 10]) 