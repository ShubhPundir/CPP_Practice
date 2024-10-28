class Widget: public Base {
    public: // delegation happens when one Ctor calls another - code refactored
        Widget(): Widget(defaultFlex) fg // #1: calls #2
        explicit Widget(double fl): Widget(0, fl) fg // #2: calls #5
        explicit Widget(int sz): Widget(sz, defaultFlex) fg // #3: calls #5
        Widget(const Widget& w): Base(w), size(w.size), flex(w.flex) { regObj(this); } // #4: same
        private:
            Widget(int sz, double fl): Base(calc()), size(sz), flex(fl) { regObj(this); } // #5: new
};