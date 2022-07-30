#pragma once
/*
taskkill /F /IM "Derivative.exe"
*/
#include <iostream>
#include <string>
#include <vector>

// 0. 0, 1, 2, 3, ...
// 1. +[1], -[2], /[3], *[4], ^[5], log[6]
// 2. sin[1], cos[2], tan[3]
// 3. 65-90 , 97-122



struct Node {
	int arr[2] = { 0,0 };
	double num = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int data0, int data1) {
		//Node* node = new Node();
		arr[0] = data0;
		arr[1] = data1;
		num = (!data0) * data1;
		left = right = nullptr;
	}
};
/*Node* creteNode(int data0, int data1) {
	Node* node = new Node();
	node->arr[0] = data0;
	node->arr[1] = data1;
	node->left = node->right = nullptr;
	return node;
}*/

std::string readNode(Node* node);
Node* copy(Node* node);
void deleteTree(Node* node);
void deleteBranches(Node* node);
void printNode(Node* root, int space = 0);
Node* textToNode(std::string arr);
Node* solveNode(Node* node);
Node* diff(Node* node, std::string wrt = "x");
std::string nodeToText(Node* node);


int main() {

	int noOfEq = -1, eqNo = 0;
	std::vector<std::string> eqStrArr;
	eqStrArr.reserve(7);
	std::vector<Node> eqArr;
	eqArr.reserve(7);

	int homeOption = 1, menuOption = 0;
	while (1 <= homeOption && homeOption <= 2) {
		homeOption = 1; menuOption = 0;
		system("cls");
		std::cout << "Home Page/\n\t\tDerivative Calculator\n\n";
		std::cout << "\t1. Enter Eq.\n";
		std::cout << "\t2. Chose Eq.\n";
		std::cout << "\n\t0. Exit\n";
		std::cout << "\n\t| ";
		std::cin >> homeOption;
		system("cls");

		switch (homeOption) {
		case 1: {////////////////////////////////////////////////
			system("cls");
			std::cout << "Home Page/Enter Eq.\n\n";

			std::cout << "\tSyntax:\n";
			std::cout << "\t1. __+__    | Or -, *, /, ^\n\t\t    |\n";
			std::cout << "\t2. sin(__)  | Or cos, tan\n\t\t    |\n";
			std::cout << "\t3. (__)(__) | But NO! 2x or 2sinx <- Bad\n\t\t    |\n";
			std::cout << "\t4. var is x |\t\t--feel free: sin(cos(tan(x+123)))\n";


			std::string eqText;
			std::cout << "\n\n\tEnter Eq. : ";
			std::cin >> eqText;
			eqStrArr.emplace_back(eqText);
			eqArr.emplace_back(*textToNode(eqText));
			noOfEq++; eqNo = noOfEq;

			std::cout << "\n-------------------------\n\n\tEquation:\n\t" << nodeToText(&eqArr[noOfEq]) << "\n\n\tTree Form:\n";

			printNode(&eqArr[noOfEq]);


			/*
			Node root(1, 1);

			root.left					= new Node(1, 2);
			root.right					= new Node(1, 3);

			root.left->left				= new Node(1, 4);
			root.left->right			= new Node(0, 5);
			root.right->left			= new Node(0, 6);
			root.right->right			= new Node(0, 7);

			root.left->left->left		= new Node(0, 8);
			root.left->left->right		= new Node(0, 9);
			root.left->right->left		= new Node(2, 0);
			root.left->right->right		= new Node(2, 1);
			root.right->left->left		= new Node(2, 2);
			root.right->left->right		= new Node(2, 3);
			root.right->right->left		= new Node(2, 4);
			root.right->right->right	= new Node(2, 5);

			deleteBranches(&root);


			printNode(&root);//*/

			menuOption = 1;

			std::cout << "\n\n\n";
			system("pause>0");
			system("cls");
			break;
		}

		case 2: {////////////////////////////////////////////////
			system("cls");
			std::cout << "Home Page/Chose Eq.\n\n";

			if (!!noOfEq) {

				for (int c = 0; c < eqStrArr.size(); c++)
					std::cout << "\t" << c + 1 << ". " << eqStrArr[c] << "\n";

				std::cin >> eqNo;
				eqNo = (!!eqNo) * (eqNo - 1);
				menuOption = 2;

			}

			//std::cout << "\n\n\n";
			//system("pause>0");
			system("cls");
			break;
		}

		default: break;
		}

		while (1 <= menuOption && menuOption <= 3) {
			system("cls");
			std::cout << "Home Page/Main/\n\t\tMain Menu\n\n";
			std::cout << "\t1. Display\n";
			std::cout << "\t2. Solve\n";
			std::cout << "\t3. Derivative\n";
			std::cout << "\t4. Both 1 & 2\n";
			std::cout << "\n\t0. Exit\n";
			std::cout << "\n\t| ";
			std::cin >> menuOption;
			system("cls");

			switch (menuOption) {
			case 1: {////////////////////////////////////////////////
				system("cls");
				std::cout << "Home Page/Main/Display\n\n";

				std::cout << "\tEq " << eqNo + 1 << ": " << eqStrArr[eqNo] << "\n\n\tTree form:\n\n";
				printNode(&eqArr[eqNo]);
				std::cout << "\n";


				std::cout << "\n\n\n";
				system("pause>0");
				system("cls");
				break;
			}

			case 2: {////////////////////////////////////////////////
				system("cls");
				std::cout << "Home Page/Main/Solve\n\n";

				std::cout << "\tEq " << eqNo + 1 << ":\n";
				printNode(&eqArr[eqNo]);
				std::cout << "\n-----------------------\n\n\t" << eqStrArr[eqNo] << " = ";
				Node* tempPtr = solveNode(&eqArr[eqNo]);

				std::cout << nodeToText(tempPtr) << "\n\nTree Form:\n\n";
				printNode(tempPtr);

				std::cout << "\n\n\n";
				system("pause>0");
				system("cls");
				break;
			}

			case 3: {////////////////////////////////////////////////
				system("cls");
				std::cout << "Home Page/Main/Derivative\n\n";

				std::cout << "\tEq " << eqNo + 1 << ":\t\t" << eqStrArr[eqNo] << "\n";
				printNode(&eqArr[eqNo]);
				std::cout << "\n-----------------------\n\n";
				std::cout << "\tEq " << eqNo + 1 << ":\t\t" << eqStrArr[eqNo] << "\n\n";
				std::cout << "\tDerivative:\t";
				Node* tempPtr = diff(&eqArr[eqNo]);
				std::cout << nodeToText(tempPtr) << "\n\n";
				//printNode(tempPtr); std::cout << "\n";

				Node* tempPtr2 = solveNode(tempPtr);
				std::cout << "\tSimplified:\t" << nodeToText(tempPtr2) << "\n\n\tTree Form:\n\n";
				printNode(tempPtr2);




				std::cout << "\n\n\n";
				system("pause>0");
				system("cls");
				break;
			}

			case 4: {////////////////////////////////////////////////
				system("cls");
				std::cout << "Home Page/Main/Derivative [@ x = ?]\n\n";



				std::cout << "\tEq " << eqNo + 1 << ":\t\t" << eqStrArr[eqNo] << "\n";
				printNode(&eqArr[eqNo]);
				std::cout << "\n-----------------------\n\n";

				std::cout << "\n\n\tComing Soon...\n";


				std::cout << "\n\n\n";
				system("pause>0");
				system("cls");
				break;
			}
			default: break;
			}




			system("cls");
		}

	}

	system("pause>0");
	system("cls");


}


std::string readNode(Node* node) {

	if (node->arr[0] == 0) {
		if (node->arr[1] == node->num) return std::to_string(node->arr[1]);
		else return std::to_string(node->num);
	}

	if (node->arr[0] == 1) {
		switch (node->arr[1]) {
		case 1: return "+";
		case 2: return "-";
		case 3: return "*";
		case 4: return "/";
		case 5: return "^";
		case 6: return "log";
		default:break;
		}
	}

	if (node->arr[0] == 2) {
		switch (node->arr[1]) {
		case 1: return "sin";
		case 2: return "cos";
		case 3: return "tan";
		default:break;
		}
	}

	if (node->arr[0] == 3) {
		std::string temp;
		temp = ((char)(node->arr[1]));
		return temp;
	}

	return "N/A";
}
Node* copy(Node* node) {
	if (node == NULL) { return NULL; }
	Node* temp = new Node(0, 0);

	temp->arr[0] = node->arr[0];
	temp->arr[1] = node->arr[1];
	temp->num = node->num;

	temp->left = copy(node->left);
	temp->right = copy(node->right);
	return temp;
}
void deleteTree(Node* node) {
	if (node == NULL) return;

	/* first delete both subtrees */
	deleteTree(node->left);
	deleteTree(node->right);

	/* then delete the node */
	//std::cout << "\n Deleting node: " << readNode(node);
	delete node;
}
void deleteBranches(Node* node) {
	if (node == NULL) return;

	/* first delete both subtrees */
	if (node->left == NULL) return;
	else { deleteTree(node->left); node->left = nullptr; }

	if (node->right == NULL) return;
	else { deleteTree(node->right); node->right = nullptr; }
}
void printNode(Node* root, int space) {
	int COUNT = 10;
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	printNode(root->right, space);

	// Print current node after space
	// count
	std::cout << "\n";
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout << "\t" << readNode(root) << "[" << root->arr[0] << ", " << root->arr[1] << "]";


	// Process left child
	printNode(root->left, space);
}

std::string nodeToText(Node* node) {
	if (node == nullptr) return "NULL";
	//std::cout << "\nCurrent Node: " << readNode(node);

	std::string tempLeft, tempRight;
	if (node->left != nullptr) { tempLeft = nodeToText(node->left); }
	if (node->right != nullptr) { tempRight = nodeToText(node->right); }

	std::string ret;

	switch (node->arr[0]) {
	case 0: {
		return readNode(node);
		break;
	}
	case 1: {
		// 1. +[1], -[2], *[3], /[4], ^[5], log[6]
		switch (node->arr[1]) {
		case 1: {
			return "(" + tempLeft + "+" + tempRight + ")";
			break;
		}
		case 2: {
			return "(" + tempLeft + "-" + tempRight + ")";
			break;
		}
		case 3: {
			return "(" + tempLeft + "*" + tempRight + ")";
			break;
		}
		case 4: {
			return "(" + tempLeft + "/" + tempRight + ")";
			break;
		}
		case 5: {
			return "(" + tempLeft + "^" + tempRight + ")";
			break;
		}
		default: break;
		}

		break;
	}
	case 2: {
		switch (node->arr[1]) {
		case 1: {
			return "sin(" + tempLeft + ")";
			break;
		}
		case 2: {
			return "cos(" + tempLeft + ")";
			break;
		}
		case 3: {
			return "tan(" + tempLeft + ")";
			break;
		}
		}
		break;
	}
	case 3: {
		return readNode(node);
		break;
	}
	default: break;
	}
	return ret;
}
Node* textToNode(std::string arr) {
	// 2sin(x)
	// xyz
	//std::cout << "\nMain: " << arr << "\n";

	Node* root = new Node(0, 0);

	int funcBool = 0, openBrackets = 0;
	std::string sub;

	//////////////// + /////////////////
	int binArr[5] = { 43, 45, 42, 47, 94 }; // + - * / ^
	for (int i = 0; i < 5; i++) {

		sub = "";
		openBrackets = 0;
		for (int c = 0; c < arr.length(); c++) {

			if ((int)arr[c] == 40) openBrackets++;
			if ((int)arr[c] == 41) openBrackets--;
			if (!openBrackets && (int)arr[c] == binArr[i]) {
				funcBool = 1;
				//std::cout << "\nsub0: " << sub << "\n";
				root->arr[0] = 1;
				root->arr[1] = i + 1;
				root->left = textToNode(sub);

				sub = "";
				for (int cc = c + 1; cc < arr.length(); cc++) {
					sub += arr[cc];
				}
				//std::cout << "\nsub1: " << sub << "\n";
				root->right = textToNode(sub);
				return root;
			}
			sub += arr[c];
		}
		//std::cout << "func" << i + 1  << ": " << funcBool << "\n";

	}



	//////////////// () //////////////// (2)((2)(3)+sin(tan(234))-(2)^(2))-3
	sub = "";
	if ((int)arr[0] == 40) {
		openBrackets = 1;
		for (int c = 1; c < arr.length(); c++) {
			funcBool = 96;

			if ((int)arr[c] == 40) openBrackets++;
			if ((int)arr[c] == 41) openBrackets--;
			if (!openBrackets) {

				std::cout << "\n" << sub << "\n";
				if (arr.length() > c + 1) {
					root->left = textToNode(sub);
					switch (arr[c + 1]) {
					case '+': root->arr[0] = 1; root->arr[1] = 1; break;
					case '-': root->arr[0] = 1; root->arr[1] = 2; break;
					case '*': root->arr[0] = 1; root->arr[1] = 3; break;
					case '(': root->arr[0] = 1; root->arr[1] = 3; break; // ()()
					case '/': root->arr[0] = 1; root->arr[1] = 4; break;
					case '^': root->arr[0] = 1; root->arr[1] = 5; break;
					default: break;
					}
					if (root->arr[0] != 1) { root->arr[0] = 1; root->arr[1] = 3; }

					sub = "";
					for (int cc = c + 1; cc < arr.length(); cc++) {
						sub += arr[cc];
					}

					std::cout << "\n" << sub << "\n";
					root->right = textToNode(sub);

					return root;

				}
				else {
					root = textToNode(sub);
					return root;
				}

			}
			sub += arr[c];
		}

	}
	//std::cout << "func+: " << funcBool << "\n";



	//////////////// sin //////////////// (sin(cos(34)))/(tan(cos(43)))
	int unaryArr[3][3] = { {115,105,110}, {99,111,115}, {116,97,110} };
	for (int i = 0; i < 3; i++) {

		sub = "";
		if ((int)arr[0] == unaryArr[i][0] && (int)arr[1] == unaryArr[i][1] && (int)arr[2] == unaryArr[i][2] && (int)arr[3] == 40) {
			funcBool = 21;
			root->arr[0] = 2;
			root->arr[1] = i + 1;

			openBrackets = 1;
			for (int cc = 4; 1; cc++) {
				if ((int)arr[cc] == 40) openBrackets++;
				if ((int)arr[cc] == 41) openBrackets--;
				if (!openBrackets && (int)arr[cc] == 41) break;
				sub += arr[cc];
			}
			if (sub.length() == 0)sub = "0";

			//std::cout << "\nsubSin: " << sub << "\n";
			root->left = textToNode(sub);
			root->right = nullptr;
			return root;
		}
		//std::cout << "func" << i + 1 << ": " << funcBool << "\n";
	}


	int integer = 0;
	for (int c = 0; c < arr.length(); c++) {
		if ((97 <= (int)arr[c] && (int)arr[c] <= 122) || (65 <= (int)arr[c] && (int)arr[c] <= 90)) {
			integer += ((int)arr[c]);
			root->arr[0] = 3;
			break;
		}
	}
	if (root->arr[0] == 3) { root->arr[1] = integer; return root; }

	integer = 0;
	for (int c = 0; c < arr.length(); c++)
		if (48 <= (int)arr[c] && (int)arr[c] <= 57) {
			integer += ((int)arr[c] - 48) * pow(10, ((int)arr.length() - 1 - c));
			root->arr[0] = 0;
		}
	if (root->arr[0] == 0) { root->arr[1] = integer; root->num = integer; return root; }
	else {
		root->arr[0] = 0;
		root->arr[1] = 0;
	}

	return root;
}

Node* solveNode(Node* node) {
	if (node == nullptr) return nullptr;
	//std::cout << "\n" << readNode(node) << "\n";

	Node* tempLeft = nullptr, * tempRight = nullptr;
	if (node->left != nullptr) { tempLeft = solveNode(node->left); }
	if (node->right != nullptr) { tempRight = solveNode(node->right); }

	Node* retNode = new Node(node->arr[0], node->arr[1]);

	switch (retNode->arr[0]) {
	case 0: {
		break;
	}
	case 1: {
		// 1. +[1], -[2], *[3], /[4], ^[5], log[6]
		switch (node->arr[1]) {
		case 1: {
			if ((tempLeft->arr[0] == 0 && tempLeft->num == 0)) { // + 0
				deleteTree(retNode);
				retNode = copy(solveNode(node->right));
				return retNode;
			}
			else if ((tempRight->arr[0] == 0 && tempRight->num == 0)) { // 0 +
				deleteTree(retNode);
				retNode = copy(solveNode(node->left));
				return retNode;
			}
			else if (tempLeft->arr[0] == 0 && tempRight->arr[0] == 0) { // num num
				retNode->arr[0] = 0;
				retNode->num = tempLeft->num + tempRight->num;
				retNode->arr[1] = retNode->num;
				return retNode;
			}
			break;
		}
		case 2: {
			if ((tempRight->arr[0] == 0 && tempRight->num == 0)) { // num 0
				deleteTree(retNode);
				retNode = copy(solveNode(node->left));
				return retNode;
			}
			else if ((tempLeft->arr[0] == 0) && (tempRight->arr[0] == 0) && ((tempLeft->num == tempRight->num) || (tempLeft->arr[1] == tempRight->arr[1]))) { // 0 num
				retNode->arr[0] = 0;
				retNode->arr[1] = 0;
				retNode->num = 0;
				return retNode;
			}
			else if (tempLeft->arr[0] == 0 && tempRight->arr[0] == 0) { // num num
				retNode->arr[0] = 0;
				retNode->num = tempLeft->num - tempRight->num;
				retNode->arr[1] = retNode->num;
				return retNode;
			}
			break;
		}
		case 3: {
			if ((tempLeft->arr[0] == 0 && tempLeft->num == 0) || (tempRight->arr[0] == 0 && tempRight->num == 0)) { //0 || 0
				retNode->arr[0] = 0; retNode->arr[1] = 0; retNode->num = 0;
				return retNode;
			}
			else if ((tempLeft->arr[0] == 0 && tempLeft->num == 1)) { // 1 ||
				deleteTree(retNode);
				retNode = copy(solveNode(node->right));
				return retNode;
			}
			else if ((tempRight->arr[0] == 0 && tempRight->num == 1)) { // || 1
				deleteTree(retNode);
				retNode = copy(solveNode(node->left));
				return retNode;
			}
			else if (tempLeft->arr[0] == 0 && tempRight->arr[0] == 0) { // num
				retNode->arr[0] = 0;
				retNode->num = tempLeft->num * tempRight->num;
				retNode->arr[1] = retNode->num;
				return retNode;
			}
			break;
		}
		case 4: {
			if ((tempRight->arr[0] == 0 && (tempRight->num == 0 || tempRight->arr[1] == 0))) {
				std::cout << "\nError: Div/0\n";
				retNode->arr[0] = 0;
				retNode->num = 9999999999;
				retNode->arr[1] = node->num;
				return retNode;
			}
			else if ((tempLeft->arr[0] == 0 && (tempLeft->num == 0 || tempLeft->arr[1] == 0))) { // 0 num
				retNode->arr[0] = 0;
				retNode->arr[1] = 0;
				retNode->num = 0;
				return retNode;
			}
			else if (tempLeft->arr[0] == 0 && tempRight->arr[0] == 0) { // num num
				retNode->arr[0] = 0;
				if (tempRight->num != 0) {
					retNode->num = tempLeft->num / tempRight->num;
				}
				retNode->arr[1] = retNode->num;
				return retNode;
			}
			break;
		}
		case 5: {
			if (tempRight->arr[0] == 0 && tempRight->num == 0) {
				retNode->arr[0] = 0;
				retNode->arr[1] = 1;
				retNode->num = 1;
				return retNode;
			}
			else if (tempRight->arr[0] == 0 && tempRight->num == 1) {
				deleteTree(retNode);
				retNode = copy(solveNode(node->left));
				return retNode;
			}
			else if (tempLeft->arr[0] == 0 && tempRight->arr[0] == 0) {
				retNode->arr[0] = 0;
				retNode->num = pow(tempLeft->arr[1], tempRight->arr[1]);
				retNode->arr[1] = retNode->num;
				return retNode;
			}
			break;
		}
		default: break;
		}

		break;
	}
	case 2: {

		if (tempLeft->arr[0] == 0) {
			retNode->arr[0] = 0;
			switch (retNode->arr[1]) {
			case 1: {
				retNode->num = sin(0.0174532925199f * tempLeft->num);
				break;
			}
			case 2: {
				retNode->num = cos(0.0174532925199f * tempLeft->num);
				break;
			}
			case 3: {
				if (((int)tempLeft->num + 90) % 180 != 0) {
					retNode->num = tan(0.0174532925199f * tempLeft->num);
				}
				else {
					std::cout << "\nError: inf, tan(n * pi)\n";
					retNode->num = 9999999999;
				}
				break;
			}
			default: break;
			}

			retNode->arr[1] = retNode->num;
			return retNode;
		}
		break;
	}
	case 3: {
		break;
	}
	default: break;
	}

	retNode->left = tempLeft;
	retNode->right = tempRight;
	return retNode;
}
Node* diff(Node* node, std::string wrt) {
	if (node == nullptr) return nullptr;

	/*std::cout << "\nBefore:\n-----------------\n";
	printNode(node);
	std::cout << "\n-----------------\n";*/

	Node* tempLeft = nullptr, * tempRight = nullptr;
	if (node->left != nullptr) { tempLeft = diff(node->left); }
	if (node->right != nullptr) { tempRight = diff(node->right); }

	Node* retNode = new Node(node->arr[0], node->arr[1]);

	switch (retNode->arr[0]) {
	case 0: {
		retNode->num = 0;
		retNode->arr[1] = 0;
		break;
	}
	case 1: {
		// 1. +[1], -[2], *[3], /[4], ^[5], log[6]
		switch (retNode->arr[1]) {
		case 1: {
			retNode->left = tempLeft;
			retNode->right = tempRight;
			break;
		}
		case 2: {
			retNode->left = tempLeft;
			retNode->right = tempRight;
			break;
		}
		case 3: {
			retNode->arr[1] = 1;

			retNode->left = new Node(1, 3);
			retNode->right = new Node(1, 3);

			retNode->left->right = copy(node->left);
			retNode->left->left = tempRight;
			retNode->right->right = copy(node->right);
			retNode->right->left = tempLeft;

			break;
		}
		case 4: {
			retNode->arr[0] = 1; retNode->arr[1] = 4; // /

			retNode->left = new Node(1, 2); // -

			retNode->left->left = new Node(1, 3); // mul
			retNode->left->left->left = copy(node->right);
			retNode->left->left->right = tempLeft;

			retNode->left->right = new Node(1, 3); // mul
			retNode->left->right->left = copy(node->left);
			retNode->left->right->right = tempRight;


			retNode->right = new Node(1, 5); // ^
			retNode->right->left = copy(node->right);
			retNode->right->right = new Node(0, 2);// 2


			break;
		}
		case 5: {

			retNode->arr[1] = 3;

			retNode->left = new Node(1, 5);

			retNode->left->left = copy(node->left);
			retNode->left->right = new Node(1, 2);

			retNode->left->right->left = copy(node->right);
			retNode->left->right->right = new Node(0, 1);

			retNode->right = new Node(1, 3);
			retNode->right->left = tempLeft;
			retNode->right->right = copy(node->right); // Can't use (node->right) two times

			break;
		}
		default: break;
		}
		break;
	}
	case 2: {
		switch (retNode->arr[1]) {
		case 1: {
			retNode->arr[0] = 1; retNode->arr[1] = 3; // *

			retNode->right = tempLeft; // \/\/\/\/'

			retNode->left = new Node(2, 2); //cos
			retNode->left->left = new Node(*node->left); // \/\/\/\/
			break;
		}
		case 2: {
			retNode->arr[0] = 1; retNode->arr[1] = 2; // -
			retNode->left = new Node(0, 0);

			retNode->right = new Node(1, 3); // mul

			retNode->right->right = tempLeft; // \/\/\/\/'

			retNode->right->left = new Node(2, 1); // sin

			retNode->right->left->left = new Node(*node->left); // \/\/\/\/


			break;
		}
		case 3: {
			retNode->arr[0] = 1; retNode->arr[1] = 4;// /

			retNode->left = tempLeft;

			retNode->right = new Node(1, 5);// ^
			retNode->right->right = new Node(0, 2);// 2
			retNode->right->left = new Node(2, 2);// cos
			retNode->right->left->left = new Node(*node->left);

			break;
		}
		default: break;
		}
		break;
	}
	case 3: {
		if (readNode(retNode) == wrt) {
			retNode->arr[0] = 0;
			retNode->num = 1; retNode->arr[1] = 1;
		}
		else {
			retNode->arr[0] = 0;
			retNode->num = 0; retNode->arr[1] = 0;
		}
		break;
	}
	default: break;
	}

	/*std::cout << "\nAfter\n-----------------\n";
	printNode(retNode);
	std::cout << "\n-----------------\n";*/

	return retNode;
}