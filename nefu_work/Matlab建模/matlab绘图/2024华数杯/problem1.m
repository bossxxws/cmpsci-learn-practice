clc;
clear;
%          theta       d      ai     alphai
L1 = Link([0 600 0 0], 'modified');
L2 = Link([0 0 300 -90 * pi / 180], 'modified'); L2.offset = -pi / 2;
L3 = Link([0 0 1200 0], 'modified'); %L3.offset=-pi/2;
L4 = Link([0 1200 300 -90 * pi / 180], 'modified'); L4.offset = pi;
L5 = Link([0 0 0 -90 * pi / 180], 'modified'); L5.offset = -pi / 2;
L6 = Link([0 0 0 -90 * pi / 180], 'modified');

L1.qlim = [-160 * pi / 180, 160 * pi / 180];
L2.qlim = [-150 * pi / 180, 15 * pi / 180];
L3.qlim = [-200 * pi / 180, 80 * pi / 180];
L4.qlim = [-180 * pi / 180, 180 * pi / 180];
L5.qlim = [-120 * pi / 180, 120 * pi / 180];
L6.qlim = [-180 * pi / 180, 180 * pi / 180];

IRB4600 = SerialLink([L1 L2 L3 L4 L5 L6], 'name', '机械臂');
IRB4600.display();
%IRB4600.teach;
IRB4600.plot([0, 0, 0, 0, 0, 0]);
