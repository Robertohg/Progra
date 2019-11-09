#include <iostream>
#include <queue>
using namespace std;



//posicion de x, posicion de y, matriz, tamano de la matriz, numero a encontrar, contenedor para las posiciones
void Floodfill(int pos_x ,int  pos_y, int *mat[], int n, int num,queue<int> visitado) {
	if (pos_x >= n || pos_y >= n)
		return;
	if (pos_x  <0 || pos_y < 0)
		return;
	if (mat[pos_x][pos_y] == 0)
		return;
	if (mat[pos_x][pos_y] = num) {
		mat[pos_x][pos_y] = 0;
		visitado.push(pos_x);
		visitado.push(pos_y);
		//visita todas las posiciones adyacentes
		Floodfill(pos_x - 1, pos_y - 1, mat, n, num,visitado);
		Floodfill(pos_x - 1, pos_y, mat, n, num, visitado);
		Floodfill(pos_x - 1, pos_y + 1, mat, n, num, visitado);
		Floodfill(pos_x, pos_y - 1, mat, n, num, visitado);
		Floodfill(pos_x, pos_y + 1, mat, n, num, visitado);
		Floodfill(pos_x + 1, pos_y - 1, mat, n, num, visitado);
		Floodfill(pos_x + 1, pos_y, mat, n, num, visitado);
		Floodfill(pos_x + 1, pos_y + 1, mat, n, num, visitado);
	}
	for (int i = 0; i <= visitado.size();) {

		cout << "Posicion x: " << visitado.front();
		visitado.pop();
		cout<<", Posicion y: " << visitado.front();
		visitado.pop();
		i += 2;
	}
}


int main()
{
	std::cout << "Hello World!\n";
}