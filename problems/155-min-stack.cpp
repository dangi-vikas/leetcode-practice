class MinStack {
	public:
		stack<int>s;
		int minElement = INT_MAX;                       

		void push(int val) {

            /*whenever val is lesser than current minElement, store current 
              minElement in stack and make val as current minElement*/
			if(minElement>=val){
				s.push(minElement);
				 minElement = val;
			}
			  s.push(val);
		}

		void pop() {

            /*top is minElement then previous element will be previous minElement, 
              so pop and store current top as current MinElement*/
			if(minElement==s.top()){
				s.pop();
				minElement = s.top();
			}
			s.pop();
		}

		int top() {
            
            // return stack top
			return s.top();
		}

		int getMin() {
            
            //return minElement
			return minElement;
		}
	};