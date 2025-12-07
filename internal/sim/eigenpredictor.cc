// // #include "eigenpredictor.h"
// // #include <Eigen/Dense>
// // #include <Eigen/IterativeLinearSolvers>
// // #include <iostream>
// // #include <vector>
// // #include <random>
// // #include <numeric>
// // #include <iostream>
// // #include <algorithm>
// // #include <iomanip>
// // #include <math.h>

// // std::pair<Eigen::MatrixXf, Eigen::MatrixXf> GenerateData(size_t n) {
// //   std::vector<float> x_data(n);
// //   std::iota(x_data.begin(), x_data.end(), 0);
// //   std::vector<float> y_data(n);
// //   std::iota(y_data.begin(), y_data.end(), 0);

// //   // mutate data
// //   std::random_device rd;
// //   std::mt19937 re(rd());
// //   std::uniform_real_distribution<float> dist(-1.0f , 1.0f);//1st Best
// //   //int i = 0;
// //   for (auto& x : x_data) {
// //      //ORIGINAL 
// //     x += dist(re);  // add noise
// //   }


// //   for (auto& y : y_data) {
// //          //ORIGINAL 
// //     y += dist(re);  // add noise
// // 	//std::cout << " MY FIRST Y INDEX: " << i << "=" << y; 
// // 	//i++;

// //   }

// //   // Make result
// //   Eigen::Map<Eigen::MatrixXf> x(x_data.data(), static_cast<Eigen::Index>(n), 1);
// //   Eigen::Map<Eigen::MatrixXf> y(y_data.data(), static_cast<Eigen::Index>(n), 1);
 
// //   return {x, y};
// // }


// //   float holdB=4.0f;
// //   float holdX=0.3f;
// //   float xSumRow1=0.0f;
// //   float xSumRow2=0.0f;
// //   float xSumRow3=0.0f;
// //   float xSumRow4=0.0f;
// //   float xSumRow5=0.0f;
// //   float xSumRow6=0.0f;

// //   float xSumCol1=0.0f;
// //   float xSumCol2=0.0f;
// //   float xSumCol3=0.0f;
// //   float xSumCol4=0.0f;
// //   float xSumCol5=0.0f;
// //   float xSumCol6=0.0f;
  
// //   float xBall = 0.0f;
// //   float yBall = 0.0f;
  
// //   float myDate=18.0;
// //   int myMonth=3;
// //   int myMultiplier=0;
  
// //   size_t m = 6;
// //   size_t l = 6;
// //   size_t n = 108;
  
// // using namespace std;

// // void computeDateOnly(const Eigen::ArrayXXf& x, int& multiplxxx, float& aDate)
// // {
// // 	int i=0;
// // 	int j=0;
// // 	int k=0;
// // 	int holdB_or_Date =aDate;
// // 	float holdChange =0.0f;


// // 	for (i=0; i<m; i++)
// // 	{
// // 		for(j=0; j<l; j++)
// // 		{
// // 			cout << "[R" <<i << ":C"<<j<<"] "<<(x(i,j))*multiplxxx << "  			" ;
// // 			if(i ==0)
// // 			{
// // 				xSumRow1 = xSumRow1 + (x(i,j));
// // 				if(j==1){xBall = (x(i,j)) -1;}
// // 			}
// // 			if(i ==1)
// // 			{
// // 				xSumRow2 = xSumRow2 + (x(i,j));
// // 			}
// // 			if(i ==2)
// // 			{
// // 				xSumRow3 = xSumRow3 + (x(i,j));
// // 			}
// // 			if(i ==3)
// // 			{
// // 				xSumRow4 = xSumRow4 + (x(i,j));
// // 			}
// // 			if(i ==4)
// // 			{
// // 				xSumRow5 = xSumRow5 + (x(i,j));
// // 			}
// // 			if(i ==5)
// // 			{
// // 				xSumRow6 = xSumRow6 + (x(i,j));
// // 			}
// // 			//----------------------------
// // 			if(j ==0)
// // 			{
// // 				xSumCol1 = xSumCol1 + (x(i,j));
// // 				//if(j==1){xBall = (x(i,j)) -1;}
// // 			}
// // 			if(j ==1)
// // 			{
// // 				xSumCol2 = xSumCol2 + (x(i,j));
// // 			}
// // 			if(j ==2)
// // 			{
// // 				xSumCol3 = xSumCol3 + (x(i,j));
// // 			}
// // 			if(j ==3)
// // 			{
// // 				xSumCol4 = xSumCol4 + (x(i,j));
// // 			}
// // 			if(j ==4)
// // 			{
// // 				xSumCol5 = xSumCol5 + (x(i,j));
// // 			}
// // 			if(j ==5)
// // 			{
// // 				xSumCol6 = xSumCol6 + (x(i,j));
// // 			}
			
// // 		}
// // 		cout <<"			" << endl;
// // 	}
// // 	cout <<"			" << endl;
// // 	for(i =0; i< 12; i++)
// // 	{
// // 		if(i==0){holdChange = abs(xSumRow1); cout << "			" << endl; cout << "% DATE" << endl;}

// // 		if(i==1){holdChange = abs(xSumRow2);}
// // 		if(i==2){holdChange = abs(xSumRow3);}
// // 		if(i==3){holdChange = abs(xSumRow4);}
// // 		if(i==4){holdChange = abs(xSumRow5);}
// // 		if(i==5){holdChange = abs(xSumRow6);}
// // 		if(i==6)
// // 		{
// // 			holdChange = abs(xSumRow1);
// // 			cout << "			" << endl;
// // 			cout << "			" << endl;
// // 			holdB_or_Date = holdB;
// // 			k=0;
// // 			cout << "% B" << endl;

// // 		}
// // 		if(i==7){holdChange = abs(xSumRow2);}
// // 		if(i==8){holdChange = abs(xSumRow3);}
// // 		if(i==9){holdChange = abs(xSumRow4);}
// // 		if(i==10){holdChange = abs(xSumRow5);}
// // 		if(i==11){holdChange = abs(xSumRow6);}
		
// // 		while (holdChange > 71)
// // 		{
// // 			holdChange = holdChange/holdB_or_Date;
// // 		}
// // 		cout <<"ROW: P"<<k+1<<": "<<holdChange <<"		";
// // 		k++;
// // 	}
// // 	cout << "			" << endl;
// // 	cout << "			" << endl;
// // 	k=0;
// // 	for(i =0; i< 12; i++)
// // 	{
// // 		if(i==0){holdChange = abs(xSumCol1); cout << "			" << endl; cout << "% DATE" << endl; }

// // 		if(i==1){holdChange = abs(xSumCol2);}
// // 		if(i==2){holdChange = abs(xSumCol3);}
// // 		if(i==3){holdChange = abs(xSumCol4);}
// // 		if(i==4){holdChange = abs(xSumCol5);}
// // 		if(i==5){holdChange = abs(xSumCol6);}
// // 		if(i==6)
// // 		{
// // 			holdChange = abs(xSumCol1);
// // 			cout << "			" << endl;
// // 			cout << "			" << endl;
// // 			holdB_or_Date = holdB;
// // 			k=0;
// // 			cout << "% B" << endl;

// // 		}
// // 		if(i==7){holdChange = abs(xSumCol2);}
// // 		if(i==8){holdChange = abs(xSumCol3);}
// // 		if(i==9){holdChange = abs(xSumCol4);}
// // 		if(i==10){holdChange = abs(xSumCol5);}
// // 		if(i==11){holdChange = abs(xSumCol6);}
		
// // 		while (holdChange > 71)
// // 		{
// // 			holdChange = holdChange/holdB_or_Date;
// // 		}
// // 		cout <<"COL: P"<<k+1<<": "<<holdChange <<"		";
// // 		k++;
// // 	}
// // 	cout <<"		"<< endl;
// // 	cout << "			" << endl;
// //   	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// // 	cout << "			" << endl;
// // 	cout <<"Possible Ball: "<<xBall << endl;
// // 	cout << "			" << endl;
// // 	cout <<"REAL:ROW: P1: "<<xSumRow1 <<"		" <<"P2: "<<xSumRow2 <<"		"<<"P3: "<<xSumRow3<<"		"
// // 	<<"P4: "<<xSumRow4 <<"		"<<"P5: "<<xSumRow5 <<"		"<<"P6: "<<xSumRow6 <<"		"<<endl;

// // 	cout <<"REAL:COL: P1: "<<xSumCol1 <<"		" <<"P2: "<<xSumCol2 <<"		"<<"P3: "<<xSumCol3<<"		"
// // 	<<"P4: "<<xSumCol4 <<"		"<<"P5: "<<xSumCol5 <<"		"<<"P6: "<<xSumCol6 <<"		"<<endl;
	
// // 	cout <<"		"<< endl;
// // 	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// // 	cout <<"		"<< endl;
	
	
// // }

// // void computeDateSummation(const Eigen::ArrayXXf& x, int& aSum, float& aDate)
// // {
// // 	int i=0;
// // 	int j=0;
// // 	int k=0;
// // 	int holdB_or_Date =aDate;
// // 	float holdChange =0.0f;


// // 	for (i=0; i<m; i++)
// // 	{
// // 		for(j=0; j<l; j++)
// // 		{
// // 			cout << "[R" <<i << ":C"<<j<<"] "<<(((x(i,j))*aSum) + aDate) << "  			" ;
// // 			if(i ==0)
// // 			{
// // 				xSumRow1 = xSumRow1 + (x(i,j));
// // 				if(j==1){xBall = (x(i,j)) -1;}
// // 			}
// // 			if(i ==1)
// // 			{
// // 				xSumRow2 = xSumRow2 + (x(i,j));
// // 			}
// // 			if(i ==2)
// // 			{
// // 				xSumRow3 = xSumRow3 + (x(i,j));
// // 			}
// // 			if(i ==3)
// // 			{
// // 				xSumRow4 = xSumRow4 + (x(i,j));
// // 			}
// // 			if(i ==4)
// // 			{
// // 				xSumRow5 = xSumRow5 + (x(i,j));
// // 			}
// // 			if(i ==5)
// // 			{
// // 				xSumRow6 = xSumRow6 + (x(i,j));
// // 			}
// // 			//----------------------------
// // 			if(j ==0)
// // 			{
// // 				xSumCol1 = xSumCol1 + (x(i,j));
// // 				//if(j==1){xBall = (x(i,j)) -1;}
// // 			}
// // 			if(j ==1)
// // 			{
// // 				xSumCol2 = xSumCol2 + (x(i,j));
// // 			}
// // 			if(j ==2)
// // 			{
// // 				xSumCol3 = xSumCol3 + (x(i,j));
// // 			}
// // 			if(j ==3)
// // 			{
// // 				xSumCol4 = xSumCol4 + (x(i,j));
// // 			}
// // 			if(j ==4)
// // 			{
// // 				xSumCol5 = xSumCol5 + (x(i,j));
// // 			}
// // 			if(j ==5)
// // 			{
// // 				xSumCol6 = xSumCol6 + (x(i,j));
// // 			}
			
// // 		}
// // 		cout <<"			" << endl;
// // 	}
// // 	cout <<"			" << endl;
// // 	for(i =0; i< 12; i++)
// // 	{
// // 		if(i==0){holdChange = abs(xSumRow1); cout << "			" << endl; cout << "% DATE" << endl;}

// // 		if(i==1){holdChange = abs(xSumRow2);}
// // 		if(i==2){holdChange = abs(xSumRow3);}
// // 		if(i==3){holdChange = abs(xSumRow4);}
// // 		if(i==4){holdChange = abs(xSumRow5);}
// // 		if(i==5){holdChange = abs(xSumRow6);}
// // 		if(i==6)
// // 		{
// // 			holdChange = abs(xSumRow1);
// // 			cout << "			" << endl;
// // 			cout << "			" << endl;
// // 			holdB_or_Date = holdB;
// // 			k=0;
// // 			cout << "% B" << endl;

// // 		}
// // 		if(i==7){holdChange = abs(xSumRow2);}
// // 		if(i==8){holdChange = abs(xSumRow3);}
// // 		if(i==9){holdChange = abs(xSumRow4);}
// // 		if(i==10){holdChange = abs(xSumRow5);}
// // 		if(i==11){holdChange = abs(xSumRow6);}
		
// // 		while (holdChange > 71)
// // 		{
// // 			holdChange = holdChange/holdB_or_Date;
// // 		}
// // 		cout <<"ROW: P"<<k+1<<": "<<holdChange <<"		";
// // 		k++;
// // 	}
// // 	cout << "			" << endl;
// // 	cout << "			" << endl;
// // 	k=0;
// // 	for(i =0; i< 12; i++)
// // 	{
// // 		if(i==0){holdChange = abs(xSumCol1); cout << "			" << endl; cout << "% DATE" << endl; }

// // 		if(i==1){holdChange = abs(xSumCol2);}
// // 		if(i==2){holdChange = abs(xSumCol3);}
// // 		if(i==3){holdChange = abs(xSumCol4);}
// // 		if(i==4){holdChange = abs(xSumCol5);}
// // 		if(i==5){holdChange = abs(xSumCol6);}
// // 		if(i==6)
// // 		{
// // 			holdChange = abs(xSumCol1);
// // 			cout << "			" << endl;
// // 			cout << "			" << endl;
// // 			holdB_or_Date = holdB;
// // 			k=0;
// // 			cout << "% B" << endl;

// // 		}
// // 		if(i==7){holdChange = abs(xSumCol2);}
// // 		if(i==8){holdChange = abs(xSumCol3);}
// // 		if(i==9){holdChange = abs(xSumCol4);}
// // 		if(i==10){holdChange = abs(xSumCol5);}
// // 		if(i==11){holdChange = abs(xSumCol6);}
		
// // 		while (holdChange > 71)
// // 		{
// // 			holdChange = holdChange/holdB_or_Date;
// // 		}
// // 		cout <<"COL: P"<<k+1<<": "<<holdChange <<"		";
// // 		k++;
// // 	}
// // 	cout <<"		"<< endl;
// // 	cout << "			" << endl;
// //   	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// // 	cout << "			" << endl;
// // 	cout <<"Possible Ball: "<<xBall << endl;
// // 	cout << "			" << endl;
// // 	cout <<"REAL:ROW: P1: "<<xSumRow1 <<"		" <<"P2: "<<xSumRow2 <<"		"<<"P3: "<<xSumRow3<<"		"
// // 	<<"P4: "<<xSumRow4 <<"		"<<"P5: "<<xSumRow5 <<"		"<<"P6: "<<xSumRow6 <<"		"<<endl;

// // 	cout <<"REAL:COL: P1: "<<xSumCol1 <<"		" <<"P2: "<<xSumCol2 <<"		"<<"P3: "<<xSumCol3<<"		"
// // 	<<"P4: "<<xSumCol4 <<"		"<<"P5: "<<xSumCol5 <<"		"<<"P6: "<<xSumCol6 <<"		"<<endl;
	
// // 	cout <<"		"<< endl;
// // 	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// // 	cout <<"		"<< endl;
// // }


// // void computeDateSummation2(const Eigen::ArrayXXf& x, int& aSum, float& aDate)
// // {
// // 	int i=0;
// // 	int j=0;
// // 	int k=0;
// // 	int holdB_or_Date =aDate;
// // 	float holdChange =0.0f;


// // 	for (i=0; i<m; i++)
// // 	{
// // 		for(j=0; j<l; j++)
// // 		{
// // 			cout << "[R" <<i << ":C"<<j<<"] "<<(((x(i,j))*aDate) + aSum) << "  			" ;
// // 			if(i ==0)
// // 			{
// // 				xSumRow1 = xSumRow1 + (x(i,j));
// // 				if(j==1){xBall = (x(i,j)) -1;}
// // 			}
// // 			if(i ==1)
// // 			{
// // 				xSumRow2 = xSumRow2 + (x(i,j));
// // 			}
// // 			if(i ==2)
// // 			{
// // 				xSumRow3 = xSumRow3 + (x(i,j));
// // 			}
// // 			if(i ==3)
// // 			{
// // 				xSumRow4 = xSumRow4 + (x(i,j));
// // 			}
// // 			if(i ==4)
// // 			{
// // 				xSumRow5 = xSumRow5 + (x(i,j));
// // 			}
// // 			if(i ==5)
// // 			{
// // 				xSumRow6 = xSumRow6 + (x(i,j));
// // 			}
// // 			//----------------------------
// // 			if(j ==0)
// // 			{
// // 				xSumCol1 = xSumCol1 + (x(i,j));
// // 				//if(j==1){xBall = (x(i,j)) -1;}
// // 			}
// // 			if(j ==1)
// // 			{
// // 				xSumCol2 = xSumCol2 + (x(i,j));
// // 			}
// // 			if(j ==2)
// // 			{
// // 				xSumCol3 = xSumCol3 + (x(i,j));
// // 			}
// // 			if(j ==3)
// // 			{
// // 				xSumCol4 = xSumCol4 + (x(i,j));
// // 			}
// // 			if(j ==4)
// // 			{
// // 				xSumCol5 = xSumCol5 + (x(i,j));
// // 			}
// // 			if(j ==5)
// // 			{
// // 				xSumCol6 = xSumCol6 + (x(i,j));
// // 			}
			
// // 		}
// // 		cout <<"			" << endl;
// // 	}
// // 	cout <<"			" << endl;
// // 	for(i =0; i< 12; i++)
// // 	{
// // 		if(i==0){holdChange = abs(xSumRow1); cout << "			" << endl; cout << "% DATE" << endl;}

// // 		if(i==1){holdChange = abs(xSumRow2);}
// // 		if(i==2){holdChange = abs(xSumRow3);}
// // 		if(i==3){holdChange = abs(xSumRow4);}
// // 		if(i==4){holdChange = abs(xSumRow5);}
// // 		if(i==5){holdChange = abs(xSumRow6);}
// // 		if(i==6)
// // 		{
// // 			holdChange = abs(xSumRow1);
// // 			cout << "			" << endl;
// // 			cout << "			" << endl;
// // 			holdB_or_Date = holdB;
// // 			k=0;
// // 			cout << "% B" << endl;

// // 		}
// // 		if(i==7){holdChange = abs(xSumRow2);}
// // 		if(i==8){holdChange = abs(xSumRow3);}
// // 		if(i==9){holdChange = abs(xSumRow4);}
// // 		if(i==10){holdChange = abs(xSumRow5);}
// // 		if(i==11){holdChange = abs(xSumRow6);}
		
// // 		while (holdChange > 71)
// // 		{
// // 			holdChange = holdChange/holdB_or_Date;
// // 		}
// // 		cout <<"ROW: P"<<k+1<<": "<<holdChange <<"		";
// // 		k++;
// // 	}
// // 	cout << "			" << endl;
// // 	cout << "			" << endl;
// // 	k=0;
// // 	for(i =0; i< 12; i++)
// // 	{
// // 		if(i==0){holdChange = abs(xSumCol1); cout << "			" << endl; cout << "% DATE" << endl; }

// // 		if(i==1){holdChange = abs(xSumCol2);}
// // 		if(i==2){holdChange = abs(xSumCol3);}
// // 		if(i==3){holdChange = abs(xSumCol4);}
// // 		if(i==4){holdChange = abs(xSumCol5);}
// // 		if(i==5){holdChange = abs(xSumCol6);}
// // 		if(i==6)
// // 		{
// // 			holdChange = abs(xSumCol1);
// // 			cout << "			" << endl;
// // 			cout << "			" << endl;
// // 			holdB_or_Date = holdB;
// // 			k=0;
// // 			cout << "% B" << endl;

// // 		}
// // 		if(i==7){holdChange = abs(xSumCol2);}
// // 		if(i==8){holdChange = abs(xSumCol3);}
// // 		if(i==9){holdChange = abs(xSumCol4);}
// // 		if(i==10){holdChange = abs(xSumCol5);}
// // 		if(i==11){holdChange = abs(xSumCol6);}
		
// // 		while (holdChange > 71)
// // 		{
// // 			holdChange = holdChange/holdB_or_Date;
// // 		}
// // 		cout <<"COL: P"<<k+1<<": "<<holdChange <<"		";
// // 		k++;
// // 	}
// // 	cout <<"		"<< endl;
// // 	cout << "			" << endl;
// //   	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// // 	cout << "			" << endl;
// // 	cout <<"Possible Ball: "<<xBall << endl;
// // 	cout << "			" << endl;
// // 	cout <<"REAL:ROW: P1: "<<xSumRow1 <<"		" <<"P2: "<<xSumRow2 <<"		"<<"P3: "<<xSumRow3<<"		"
// // 	<<"P4: "<<xSumRow4 <<"		"<<"P5: "<<xSumRow5 <<"		"<<"P6: "<<xSumRow6 <<"		"<<endl;

// // 	cout <<"REAL:COL: P1: "<<xSumCol1 <<"		" <<"P2: "<<xSumCol2 <<"		"<<"P3: "<<xSumCol3<<"		"
// // 	<<"P4: "<<xSumCol4 <<"		"<<"P5: "<<xSumCol5 <<"		"<<"P6: "<<xSumCol6 <<"		"<<endl;
	
// // 	cout <<"		"<< endl;
// // 	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// // 	cout <<"		"<< endl;
// // }


// // void run_predictor() {
   
// //   //_____________________________________________________________________________________________________________________________
// //   // generate training data
// //   //_____________________________________________________________________________________________________________________________
// //   Eigen::MatrixXf x1, y;
// //   std::tie(x1, y) = GenerateData(n);
  
// //   //x0: Column of 1s: SOON MAYBE CHANGE X0 TO POSITION 6:BALL
// //   //x1: seeds: SOON MAYBE CHANGE SEEDS TO POSITION 5 OR ADD A 7th COL
// //   //x01: POSITION 1
// //   //x02: POSSITION 2
// //   //x03: POSITION 3
// //   //x04:POSITION 4
  
// //   Eigen::MatrixXf x0 = Eigen::MatrixXf::Ones(n, 1); //(nx1) MAtrix
// //   Eigen::MatrixXf x01 = Eigen::MatrixXf::Ones(n, 1);
// //   Eigen::MatrixXf x02 = Eigen::MatrixXf::Ones(n, 1);
// //   Eigen::MatrixXf x03 = Eigen::MatrixXf::Ones(n, 1);
// //   Eigen::MatrixXf x04 = Eigen::MatrixXf::Ones(n, 1);
// //   Eigen::MatrixXf x05 = Eigen::MatrixXf::Ones(n, 1);
// //   Eigen::MatrixXf x06 = Eigen::MatrixXf::Ones(n, 1);
// //   //x0 = x0 + x1;
  
// //  // cout << "X1 - OUTPUT: " <<x1 << endl;
// //   //cout << "		" <<endl;
	
// //   x01 <<10,02,04,11,8,11,03,12,14,20,06,02,06,02,36,27,07,02,02,19,10,03,03,03,10,12,18,8,10,07,40,03,
// // 	05,8,19,21,8,01,9,05,03,10,10,07,30,30,23,11,12,01,12,28,02,21,22,20,37,05,01,37,20,9,11,32,
// // 	10,03,12,27,17,16,35,06,12,07,05,01,25,01,27,15,33,01,8,26,24,8,13,04,19,8,19,44,06,11,02,03,
// // 	11,04,01,12,16,35,16,22,21,10,13,14;
  
// //   x02 <<15,15,11,29,14,15,18,21,17,21,14,13,12,06,38,29,16,13,06,20,30,25,07,21,40,15,26,32,16,20,43,16,
// // 	31,15,25,46,30,02,25,23,06,27,30,29,32,31,29,20,17,17,22,38,07,22,23,40,51,36,04,40,31,22,20,35,
// // 	20,15,22,39,36,28,36,21,18,24,21,21,30,04,28,22,46,05,21,40,29,31,20,22,29,25,28,52,07,13,8,19,
// // 	13,10,19,17,23,36,18,36,25,21,30,16;
	
// //   x03<<51,38,38,30,33,43,37,22,18,36,25,32,39,9,45,45,19,23,24,40,37,44,33,38,45,38,28,55,32,29,48,48,
// // 	34,26,43,47,48,24,34,28,26,29,51,36,48,41,47,33,30,52,54,42,11,39,37,47,54,39,18,50,38,41,22,40,
// // 	29,45,26,54,47,36,51,49,20,36,32,22,53,11,44,38,52,29,30,41,50,39,40,35,34,34,46,54,11,22,21,27,
// // 	55,37,20,20,28,47,35,48,32,26,33,23;
	
// //   x04<<61,54,49,47,36,55,51,30,21,60,33,33,48,33,62,55,48,34,51,42,53,53,50,50,56,57,38,64,63,38,59,52,
// // 	51,35,46,57,57,50,44,43,35,44,57,41,53,42,59,39,45,58,66,47,17,44,62,55,58,45,46,61,40,47,33,52,
// // 	48,51,46,56,60,39,55,65,29,54,36,34,59,59,67,54,59,54,49,55,65,43,51,38,44,38,50,64,66,27,34,37,
// // 	56,39,38,21,40,61,39,59,63,41,45,50;
	
// //  x05<<69,65,69,53,67,61,59,33,27,65,46,48,50,39,64,58,68,66,61,59,59,64,69,59,67,63,47,66,65,67,69,60,
// // 	53,45,48,62,64,57,45,56,51,58,63,43,63,48,60,65,62,64,69,52,32,60,63,63,60,57,62,63,49,61,54,54,
// // 	51,61,59,59,61,59,61,67,30,60,58,47,60,67,68,66,62,62,57,65,66,60,63,39,50,41,54,69,67,46,62,40,
// // 	69,69,54,26,63,63,53,61,67,49,61,53;
	
// //  x06<<14,11,16,16,17,10,13,24,9,13,17,22,07,11,19,02,15,02,01,15,04,10,24,06,02,24,17,10,17,22,19,01,
// // 	23,9,14,8,9,26,8,19,17,24,20,05,12,03,15,24,05,01,15,01,11,12,19,05,19,11,25,21,21,21,24,01,
// // 	17,8,26,24,15,04,26,18,16,23,14,04,05,10,11,03,10,03,8,24,14,17,01,20,25,10,9,26,19,20,16,8,
// // 	04,24,17,8,01,03,21,22,06,25,14,03;	

// // //_______________________________________________________________________________________________________________________________
// //   // setup line coeficients y = b(4) + k(0.3)*x
// //   //y.array() *= 0.3f;
// //   //y.array() += 4.f;
  
// //   y.array() *= holdX;
// //   y.array() += holdB;
  
  
// //   Eigen::MatrixXf x(n, 6);
// //   //x << x0, x1, x01, x02, x03, x04; // x0 =1 column of 1000s 1 , x1= copy random generator 1 to 1000 + decimal (dist)
// //    //x << x0, x01, x02, x03, x04, x05; //GOOD
// //    x <<x01, x02, x03, x04, x05, x06;
// // 	std::cout << "		"<< std::endl;

// //  // train estimator
// //   Eigen::LeastSquaresConjugateGradient<Eigen::MatrixXf> gd;
// //   //gd.setMaxIterations(100); // Original
// //   gd.setMaxIterations(1000);
// //   //gd.setTolerance(0.001f); // Original
// //   gd.setTolerance(0.001f);
// //   gd.compute(x);
// //   Eigen::VectorXf b = gd.solve(y);
// //   std::cout << "Estimated parameters vector : " << b << std::endl;

// //   // normal equations
// //   Eigen::VectorXf b_norm = (x.transpose() * x).ldlt().solve(x.transpose() * y);
// //   std::cout << "Estimated with normal equation parameters vector : " << b_norm
// //             << std::endl;
// //   std::cout << "		"<< std::endl;
// //   // predict
// //   //Eigen::MatrixXf new_x(5, 2); // Original is (5,2)
// //   //new_x << 1, 1, 1, 2, 1, 3, 1, 4, 1, 5; // Original
// //   Eigen::MatrixXf new_x(6, 6); // Original is (5,2): 

    
// // 	//POWERBALL: 1, 2, 3, 4, 5, BALL: date: March 18th, 2024: 
// //    new_x <<
		  
// // 		12,23,44,57,61,05,
// // 		21,29,54,59,62,04,
// // 		01,03,07,16,66,05,
// // 		30,36,49,52,63,16,
// // 		06,19,28,44,60,10,
// // 		36,42,50,52,67,26;



// // 		myDate =18;
// // 		std::cout << "date: March 18th, 2024"<< std::endl;

// //   std::cout<<std::fixed << std::setprecision(6) << std::endl;
// //   std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<< std::endl;
// //   auto new_y = new_x.array().rowwise() * b.transpose().array();
  
  
// //   std::cout << "		"<< std::endl;


// //   std::cout << "Predicted values : \n" << new_y << "		"<< std::endl;
// //   std::cout << "		"<< std::endl;

// //   auto new_y_norm = new_x.array().rowwise() * b_norm.transpose().array();
// //   std::cout << "Predicted(norm) values : \n" << new_y_norm << "		"<<  std::endl;
// //   std::cout << "		"<< std::endl;
  
// //   //-----------------------------------------------------------------------------------------------------------------------------------
// //   //COMPUTE PREDICTION:
// //   cout <<"##########################################################################" <<endl;
// //   cout << "1) - PRINTING X-VECTOR: DATE ONLY: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   myMultiplier = myDate;
// //   computeDateOnly(new_y, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "PRINTING Y-VECTOR: DATE ONLY "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   computeDateOnly(new_y_norm, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "2) - PRINTING X-VECTOR: B ONLY: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   myMultiplier = holdB;
// //   computeDateOnly(new_y, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "PRINTING Y-VECTOR: B ONLY "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   computeDateOnly(new_y_norm, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "3) - PRINTING X-VECTOR: B x DATE: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   myMultiplier = holdB * myDate;
// //   computeDateOnly(new_y, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "PRINTING Y-VECTOR: B x DATE: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   computeDateOnly(new_y_norm, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "4) - PRINTING X-VECTOR: [B + DATE]: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   myMultiplier = holdB + myDate;
// //   computeDateOnly(new_y, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "PRINTING Y-VECTOR: [B + DATE]: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   computeDateOnly(new_y_norm, myMultiplier, myDate);
  
// //   cout <<"################################################################################################################################################################################################################" <<endl;
// //   cout <<"################################################################################################################################################################################################################" <<endl;
// //   cout << "5) - PRINTING X-VECTOR: (NORM * B) + DATE: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   myMultiplier = holdB;
// //   computeDateSummation(new_y, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "PRINTING Y-VECTOR: (NORM * B) + DATE: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   myMultiplier = holdB;
// //   computeDateSummation(new_y_norm, myMultiplier, myDate);
// //   cout <<"##########################################################################" <<endl;
// //   cout << "6) - PRINTING X-VECTOR: (NORM * DATE) + B: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   myMultiplier = holdB;
// //   computeDateSummation2(new_y, myMultiplier, myDate);
  
// //   cout <<"##########################################################################" <<endl;
// //   cout << "PRINTING Y-VECTOR: (NORM * DATE) + B: "<< endl;
// //   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
// //   myMultiplier = holdB;
// //   computeDateSummation2(new_y_norm, myMultiplier, myDate);
  
// // }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% OPTIMIZATION %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%% WORKING VERSION 5.3 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#include "eigenpredictor.h"
#include <Eigen/Dense>
#include <Eigen/IterativeLinearSolvers>
#include "third_party/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cmath>

#include <unistd.h>   // for dup2
#include <fcntl.h>    // for open


//=== For the followings: C++17 is required (this codebase is limited to C++ 11)
// #include <filesystem> 
// namespace fs = std::filesystem;
#include <sys/stat.h>
namespace fs {
    inline bool exists(const std::string& path) {
        struct stat buffer;
        return (stat(path.c_str(), &buffer) == 0);
    }
}

using json = nlohmann::json;
using namespace std;

constexpr size_t m = 6;
constexpr size_t l = 6;
constexpr size_t n = 108;

// ======================================================
// Predictor constants (user-defined tracking targets)
// ======================================================
static const int kConstTargets[6] = {11, 17, 24, 35, 38, 5};

// The `Node` struct is defined in `eigenpredictor.h` (shared header).
// Use the header's definition here and keep a package-local head pointer.
static Node* gHead = nullptr; // global linked list head


// Configuration struct
struct PredictorGlobals {
    float holdB = 4.0f;
    float holdX = 0.3f;
    float xBall = 0.0f;
    float myDate = 18.0f;
    int myMonth = 3;
    int myMultiplier = 0;
};




// -----------------------------------------------------------------------------
// Generate random input data (deterministic-safe)
std::pair<Eigen::MatrixXf, Eigen::MatrixXf> GenerateData(size_t n) {
    static thread_local std::mt19937 re(std::random_device{}());
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);

    Eigen::VectorXf x_data = Eigen::VectorXf::LinSpaced(n, 0, n - 1);
    Eigen::VectorXf y_data = Eigen::VectorXf::LinSpaced(n, 0, n - 1);

    x_data = x_data.unaryExpr([&](float v) { return v + dist(re); });
    y_data = y_data.unaryExpr([&](float v) { return v + dist(re); });

    return {x_data, y_data};
}

// -----------------------------------------------------------------------------
// JSON loader for predictor input
// -----------------------------------------------------------------------------
// static PredictorInput makeDefaultInput() {
//     PredictorInput input;
//     PredictorSet set;

//     set.matrix = Eigen::MatrixXf(6, 6);
//     set.matrix <<
//         1, 0.5, 0.2, 0.8, 0.4, 0.9,
//         0.3, 0.7, 0.1, 0.9, 0.2, 0.6,
//         0.6, 0.4, 0.8, 0.1, 0.5, 0.3,
//         0.9, 0.2, 0.7, 0.3, 0.8, 0.1,
//         0.5, 0.9, 0.4, 0.2, 0.6, 0.7,
//         0.4, 0.8, 0.3, 0.9, 0.1, 0.5;

//     set.myDate = 18.0f;
//     set.dateLabel = "March 18th, 2024";

//     int defaults[6] = {11, 17, 24, 35, 38, 5};
//     std::memcpy(set.constants, defaults, sizeof(defaults));

//     set.head = nullptr;

//     input.sets.push_back(set);
//     return input;
// }

//=======
static PredictorInput makeDefaultInput() {
    PredictorInput input;

    PredictorSet set;

    set.matrix = Eigen::MatrixXf(6, 6);
    set.matrix <<
        1, 0.5, 0.2, 0.8, 0.4, 0.9,
        0.3, 0.7, 0.1, 0.9, 0.2, 0.6,
        0.6, 0.4, 0.8, 0.1, 0.5, 0.3,
        0.9, 0.2, 0.7, 0.3, 0.8, 0.1,
        0.5, 0.9, 0.4, 0.2, 0.6, 0.7,
        0.4, 0.8, 0.3, 0.9, 0.1, 0.5;

    set.myDate = 18.0f;
    set.dateLabel = "March 18th, 2024";

    int defaults[6] = {11, 17, 24, 35, 38, 5};
    std::memcpy(set.constants, defaults, sizeof(defaults));

    set.head = NULL;

    input.sets.push_back(set);
    return input;
}

PredictorInput getPredictorInput() {
    PredictorInput input;
    std::ifstream file;

    const char* paths[] = {
        "data/predictor_input.json",
        "../data/predictor_input.json",
        "../../data/predictor_input.json"
    };

    for (int i = 0; i < 3; ++i) {
        file.open(paths[i]);
        if (file.is_open()) {
            std::cout << "[INFO] Loaded JSON input from: " << paths[i] << std::endl;
            break;
        }
    }

    if (!file.is_open()) {
        std::cerr << "[WARN] predictor_input.json not found; using default input.\n";
        return makeDefaultInput();
    }

    try {
        json j;
        file >> j;
        file.close();

        if (!j.contains("sets") || !j["sets"].is_array() || j["sets"].empty()) {
            std::cerr << "[ERROR] Invalid or empty 'sets' array in JSON.\n";
            return makeDefaultInput();
        }

        int defaults[6] = {11, 17, 24, 35, 38, 5};

        for (size_t sidx = 0; sidx < j["sets"].size(); ++sidx) {
            const json& s = j["sets"][sidx];
            PredictorSet set;

            if (!s.contains("matrix") || !s["matrix"].is_array()) {
                std::cerr << "[ERROR] Missing or invalid 'matrix' in set " << sidx << ".\n";
                continue;
            }

            const json& mat = s["matrix"];
            size_t rows = mat.size();
            size_t cols = mat[0].size();

            if (rows == 0 || cols == 0) {
                std::cerr << "[ERROR] Matrix dimensions are zero in set " << sidx << ".\n";
                continue;
            }

            set.matrix = Eigen::MatrixXf(rows, cols);
            for (size_t i = 0; i < rows; ++i) {
                for (size_t jx = 0; jx < cols; ++jx) {
                    set.matrix(i, jx) = mat[i][jx].get<float>();
                }
            }

            set.myDate = s.contains("date") ? s["date"].get<float>() : 18.0f;
            set.dateLabel = s.contains("dateLabel") ? s["dateLabel"].get<std::string>() : "Unknown date";

            if (s.contains("constants") && s["constants"].is_array() && s["constants"].size() == 6) {
                for (int k = 0; k < 6; ++k)
                    set.constants[k] = s["constants"][k].get<int>();
            } else {
                std::memcpy(set.constants, defaults, sizeof(defaults));
            }

            set.head = NULL;
            input.sets.push_back(set);
        }

        std::cout << "[INFO] Loaded " << input.sets.size() << " matrix sets.\n";
        return input;
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] Failed to parse JSON: " << e.what() << "\n";
        return makeDefaultInput();
    }
}

void appendNode(Node*& head, Node* newNode) {
    if (!head) {
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = newNode;
}

void clearList(Node*& head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

//=====================================
template <typename Fn>
void computeAndPrint(const Eigen::ArrayXXf& x, int multOrSum, float date,
                     Fn op, const PredictorGlobals& g, Node*& head) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(6);
    int counter = 1;

    for (int i = 0; i < x.rows(); ++i) {
        for (int j = 0; j < x.cols(); ++j) {
            float v = x(i, j);
            float result = op(v, multOrSum, date);

            int truncVal = static_cast<int>(result);
            int minusOne = truncVal - 1;
            int plusOne = truncVal + 1;

            std::string idx = "R" + std::to_string(i) + ":C" + std::to_string(j);

            // Determine op_mode and position by comparing truncVal, minusOne, plusOne
            // against the predictor constants. We check constants in order and take
            // the first match. If truncVal matches => "As is"; if minusOne matches
            // => "(-1)"; if plusOne matches => "(+1)". If no match, set both to "none".
            std::string opMode = "none";
            std::string pos = "none";

            for (int k = 0; k < 6; ++k) {
                int c = kConstTargets[k];
                if (truncVal == c) {
                    opMode = "As is";
                    pos = "CONST_POS" + std::to_string(k + 1);
                    break;
                }
                if (minusOne == c) {
                    opMode = "(-1)";
                    pos = "CONST_POS" + std::to_string(k + 1);
                    break;
                }
                if (plusOne == c) {
                    opMode = "(+1)";
                    pos = "HIT_POS" + std::to_string(k + 1);
                    break;
                }
            }

            // Keep a position label for the node even when none matched (use matrix pos)
            if (pos == "none") pos = "MISS_POS" + std::to_string(counter);

            Node* node = new Node(idx, result, truncVal, minusOne, plusOne, opMode, pos);
            appendNode(head, node);

            out << std::setw(4) << counter++ << ") "
                << idx << " => val=" << result
                << ", trunc=" << truncVal
                << ", (-1)=" << minusOne
                << ", (+1)=" << plusOne << "\n";
        }
    }

    std::cout << out.str();
}


// -----------------------------------------------------------------------------
// Wrapper for DATE ONLY mode
void computeDateOnly(const Eigen::ArrayXXf& x, int& multiplxxx, float& aDate, Node*& head) {
    PredictorGlobals g;
    computeAndPrint(x, multiplxxx, aDate,
        [](float v, int mult, float) { return v * mult; }, g, head);
}

// Wrapper for (v * sum) + date mode
void computeDateSummation(const Eigen::ArrayXXf& x, int& aSum, float& aDate, Node*& head) {
    PredictorGlobals g;
    computeAndPrint(x, aSum, aDate,
        [](float v, int sum, float date) { return (v * sum) + date; }, g, head);
}

// Wrapper for (v * date) + sum mode
void computeDateSummation2(const Eigen::ArrayXXf& x, int& aSum, float& aDate, Node*& head) {
    PredictorGlobals g;
    computeAndPrint(x, aSum, aDate,
        [](float v, int sum, float date) { return (v * date) + sum; }, g, head);
}


void printLinkedList(Node* head) {
    std::cout << "\n\n================== LINKED LIST AGGREGATE ==================\n";
    Node* current = head;
    int count = 0;
    while (current) {
        std::cout << count << ": "
                  << current->idx << " | "
                  << current->value << " | "
                  << current->trunc << " | "
                  << current->minus1 << " | "
                  << current->plus1 << " | "
                  << current->op_mode << " | "
                  << current->position << "\n";
        current = current->next;
        count ++;
    }
    std::cout << "==========================================================\n\n";
}

//==============================================================
void run_predictor() {
    // Open the file for appending
    int fd = open("matrix_output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd != -1) {
        // Duplicate fd onto stdout (file descriptor 1)
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
    //-- both printf (C), Go fmt.Println, and std::cout go to matrix_output.txt
    //-------------
    std::ofstream logfile("matrix_output.txt", std::ios::app);
    TeeBuf tee(std::cout.rdbuf(), logfile.rdbuf());
    std::ostream out(&tee);

    // Redirect std::cout globally if you want all existing code to work:
    std::cout.rdbuf(&tee);

    // Now all std::cout calls (including inside printLinkedList) go to both console and file.
    PredictorGlobals g;

    Eigen::MatrixXf x1, y;
    std::tie(x1, y) = GenerateData(n);

    y.array() *= g.holdX;
    y.array() += g.holdB;

    //-- Simulated feature expansion which need to be replaced with real features
    Eigen::MatrixXf x01 = x1.array().sin();
    Eigen::MatrixXf x02 = x1.array().cos();
    Eigen::MatrixXf x03 = x1.array().tan();
    Eigen::MatrixXf x04 = (x1.array() * 0.3f).sin();
    Eigen::MatrixXf x05 = (x1.array() * 0.5f).cos();
    Eigen::MatrixXf x06 = (x1.array() * 0.1f).tan();

    Eigen::MatrixXf x(n, 6);
    x << x01, x02, x03, x04, x05, x06;

    cout << "\n";
    Eigen::LeastSquaresConjugateGradient<Eigen::MatrixXf> gd;
    gd.setMaxIterations(1000);
    gd.setTolerance(0.001f);
    gd.compute(x);
    Eigen::VectorXf b = gd.solve(y);
    cout << "Estimated parameters vector : " << b << endl;

    Eigen::VectorXf b_norm = (x.transpose() * x).ldlt().solve(x.transpose() * y);
    cout << "Estimated with normal equation parameters vector : " << b_norm << endl << "\n";

    // -------------------------------------------------------------------------
    // Load multiple predictor sets
    PredictorInput input = getPredictorInput();
    int matrixIndex = 1;

    for (size_t si = 0; si < input.sets.size(); ++si) {
        PredictorSet& set = input.sets[si];
        Eigen::MatrixXf new_x = set.matrix;
        g.myDate = set.myDate;

        cout << "\n\n======================= MATRIX SET #" << matrixIndex++ << " =======================\n";
        cout << "date: " << set.dateLabel << "\n"
             << fixed << setprecision(6);

        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        auto new_y = new_x.array().rowwise() * b.transpose().array();
        auto new_y_norm = new_x.array().rowwise() * b_norm.transpose().array();

        cout << "\nPredicted values : \n" << new_y << "		\n\n";
        cout << "Predicted(norm) values : \n" << new_y_norm << "		\n\n";

        // -------------------------------------------------------------------------
        // STEP 1-6 FULL SEQUENCE
        cout << "##########################################################################\n1) - PRINTING X-VECTOR: DATE ONLY:\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        g.myMultiplier = g.myDate; computeDateOnly(new_y, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\nPRINTING Y-VECTOR: DATE ONLY\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        computeDateOnly(new_y_norm, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\n2) - PRINTING X-VECTOR: DATE + SUM\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        computeDateSummation(new_y, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\nPRINTING Y-VECTOR: DATE + SUM\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        computeDateSummation(new_y_norm, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\n3) - PRINTING X-VECTOR: DATE * SUM\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        computeDateSummation2(new_y, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\nPRINTING Y-VECTOR: DATE * SUM\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        computeDateSummation2(new_y_norm, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\n4) - PRINTING X-VECTOR: [B + DATE]\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        g.myMultiplier = g.holdB; computeDateOnly(new_y, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\nPRINTING Y-VECTOR: [B + DATE]\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        g.myMultiplier = g.holdB; computeDateOnly(new_y_norm, g.myMultiplier, g.myDate, set.head);

        cout << "################################################################################################################################################################################################################\n";
        cout << "5) - PRINTING X-VECTOR: (NORM * B) + DATE\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        g.myMultiplier = g.holdB; computeDateSummation(new_y, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\nPRINTING Y-VECTOR: (NORM * B) + DATE\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        g.myMultiplier = g.holdB; computeDateSummation(new_y_norm, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\n6) - PRINTING X-VECTOR: (NORM * DATE) + B\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        g.myMultiplier = g.holdB; computeDateSummation2(new_y, g.myMultiplier, g.myDate, set.head);

        cout << "##########################################################################\nPRINTING Y-VECTOR: (NORM * DATE) + B\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        g.myMultiplier = g.holdB; computeDateSummation2(new_y_norm, g.myMultiplier, g.myDate, set.head);

        //==== FINAL OUTPUT PER MATRIX SET ====
        std::cout << "\n\n========= FINAL LINKED LIST OUTPUT FOR MATRIX =========\n";
        printLinkedList(set.head);
        clearList(set.head);
    }

    // ( future aggregate section across all sets)
}
