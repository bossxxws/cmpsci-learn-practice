clc;
clear;
%          thetai       di      ai-1     alphai-1
L1 = Link([0            495     175      -pi/2  ],'standard');
L2 = Link([0            0       1095      0     ],'standard');L2.offset=-pi/2;
L3 = Link([0            0       175      -pi/2  ],'standard');
L4 = Link([0            1230.5  0        pi/2   ],'standard');
L5 = Link([0            0       0        pi/2   ],'standard');L5.offset=-pi;
L6 = Link([0            85      0        0      ],'standard');
 
L1.qlim =[-180*pi/180, 180*pi/180];
L2.qlim =[-90*pi/180, 150*pi/180];
L3.qlim =[-180*pi/180, 75*pi/180];
L4.qlim =[-400*pi/180, 400*pi/180];
L5.qlim =[-125*pi/180, 125*pi/180];
L6.qlim =[-400*pi/180, 400*pi/180];

IRB4600=SerialLink([L1 L2 L3 L4 L5 L6], 'name', 'IRB4600');
IRB4600.display();
IRB4600.teach;
