/*Normal way*/
class ProductOfNumbers {
public:
    ProductOfNumbers() {
    	vector<int>temp;
	int product = 1;
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        product = 1, l = temp.size()-1;
        for (int i = 0; i < k; i++) {
            product *= temp[l - i];
        }
        return product;
    }
    
};

/*Using Pre_Product*/
class ProductOfNumbers {
public:
    vector<int>temp;
    ProductOfNumbers() {
        temp.push_back(1);
        int count = 0;
    }

    void add(int num) {
	//count is saving the lastest position of 0
        if(num == 0) count = temp.size(), num = 1;
        temp.push_back(temp.back()*num);
    }

    int getProduct(int k) {
        int l = temp.size()-1;
        if(count > l-k) return 0;
        return temp[l]/temp[l-k];
    }
};
