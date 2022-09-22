
#include <iostream>
// 5. Структура данных - двусвязная, на базе адресных указателей.


template <typename T>

class List {

protected:

    class Node {

    public:

        T value;
        Node* next;
        Node* prev;

        Node(T value) {
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }

    };

    Node* head;
    Node* tail;
    int size;

    int stepCount;

public:

    List(); // конструктор
    List(const List<T>& list); // конструктор копирования
    ~List(); // деструктор

    int getSize(); // опрос размера списка
    void clear(); // очистка списка
    bool isEmpty(); // проверка списка на пустоту

    bool isExisting(T value); // опрос наличия заданного значения
    T read(int index); // чтение значения с заданным номером в списке
    bool update(int index, T newval); // изменение значения с заданным номером в списке

    int getIndex(T value); // получение позиции в списке для заданного значения

    void add(T value); // включение нового значения, 
    bool add(T value, int index); // включение нового значения в позицию с заданным номером

    // проблема - при T = int перегрузка некорректна, костыль = ненужная переменная
    bool remove(T value); //удаление заданного значения из списка
    bool remove(int index, bool b); // удаление значения из позиции с заданным номером

    void show(); //  оставлено только для тестирования
    int getStepCount() { return stepCount; }


    class Iterator
    {

    private:

        Node* cur;

    public:

        Iterator(Node* ptr = nullptr) {
            cur = ptr;
        }
        Iterator(const Iterator& iterator) {
            cur = iterator.cur;
        }

        bool operator==(const Iterator& lhs) const
        {
            return (cur == lhs.cur);
        }

        bool operator!=(const Iterator& lhs) const
        {
            return (cur != lhs.cur);
        }

        Iterator operator++()
        {
            if (cur == nullptr) throw std::exception("exception");
            cur = cur->next;
            return *this;
            
        }

        Iterator operator--()
        {
            if (cur == nullptr) throw std::exception("exception");
            cur = cur->prev;
            return *this;
        }

        T& operator*() const {
            if (cur == nullptr) throw std::exception("exception");
            return cur->value;
        }

    };


    class ReverseIterator
    {

    private:

        Node* cur;

    public:

        ReverseIterator(Node* ptr = nullptr) {
            cur = ptr;
        }
        ReverseIterator(const ReverseIterator& iterator) {
            cur = iterator.cur;
        }

        bool operator==(const ReverseIterator& lhs) const
        {
            return (cur == lhs.cur);
        }

        bool operator!=(const ReverseIterator& lhs) const
        {
            return (cur != lhs.cur);
        }

        ReverseIterator operator++()
        {
            if (cur == nullptr) throw std::exception("exception");
            cur = cur->prev;
            return *this;
        }

        ReverseIterator operator--()
        {
            if (cur == nullptr) throw std::exception("exception");
            cur = cur->next;
            return *this;
        }

        T& operator*() const {
            if (cur == nullptr) throw std::exception("exception");
            return cur->value;
        }

    };

    friend class Iterator;
    friend class ReverseIterator;

    using iterator = Iterator;
    using reverse_iterator = ReverseIterator;
    
    iterator begin() {
        if (head != nullptr) return iterator(head);
        else return iterator();
    }
    iterator end() {
        if (tail != nullptr) return iterator(tail->next);
        else return iterator();
    }

    reverse_iterator rbegin() {
        if (tail != nullptr) return reverse_iterator(tail);
        else return reverse_iterator();
    }
    reverse_iterator rend() {
        if (head != nullptr) return reverse_iterator(head->prev);
        else return reverse_iterator();
    }


};

    template<typename T> List<T>::List()  // конструктор
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    template<typename T> List<T>::List(const List<T>& list) // конструктор копирования
    {
        head = tail = NULL;
        size = 0;
        Node* p = list.head;
        while (p != NULL) {
            this->add(p->value);
            p = p->next;
        }
    }

    template<typename T> List<T>::~List() // деструктор
    {
        clear();
    }

    template<typename T> int List<T>::getSize() // опрос размера списка
    {
        return size;
    }

    template<typename T> void List<T>::clear() // очистка списка
    {
        
        while (head)  //Пока по адресу на начало списка что-то есть
        {
            tail = head->next; //Резервная копия адреса следующего звена списка
            delete head;  //Очистка памяти от первого звена
            head = tail;  //Смена адреса начала на адрес следующего элемента
        }
        size = 0;

    }

    template<typename T> bool List<T>::isEmpty() // проверка на пустоту
    {
        return (head == NULL && tail == NULL && size == 0);
    }

    template<typename T> bool List<T>::isExisting(T value) // опрос наличия заданного значения
    {
        Node* p = head;
        stepCount = 0;
        while (p != NULL) {
            if (p->value == value) return true;
            p = p->next;
            stepCount++;
        }
        return false;
    }

    template<typename T> T List<T>::read(int index) // чтение значения с заданным номером в списке
    {
        if (!(index >= 0 && index < size)) throw std::exception("exception");

        /*Node* p;
        if (size >> 1 > index) {
            p = head;
            for (int i = 1; i != index; i++) p = p->next;
        }
        else {
            p = tail;
            for (int i = size; i != index; i--) p = p->prev;
        }*/

        Node* p;
        if (index <= size - 1 - index) // ближе с головы
        {
            p = head;
            for (int i = 0; i < index; i++) p = p->next;
        }
        else // ближе с хвоста
        {
            p = tail;
            for (int i = size - 1; i > index; i--) p = p->prev;
        }
        // остановились на элементе, который должны подвинуть вправо, чтобы вставить новый на его место

        return p->value;
    }

    template<typename T> bool List<T>::update(int index, T newval) // изменение значения с заданным номером в списке
    {

        if (!(index >= 0 && index < size)) return false;

        /*Node* p;
        if (size >> 1 > index) {
            p = head;
            for (int i = 1; i != index; i++) p = p->next;
        }
        else {
            p = tail;
            for (int i = size; i != index; i--) p = p->prev;
        }*/

        Node* p;
        if (index <= size - 1 - index) // ближе с головы
        {
            p = head;
            for (int i = 0; i < index; i++) p = p->next;
        }
        else // ближе с хвоста
        {
            p = tail;
            for (int i = size - 1; i > index; i--) p = p->prev;
        }
        // остановились на элементе, который должны подвинуть вправо, чтобы вставить новый на его место

        p->value = newval;
        return true;
    }

    template<typename T> int List<T>::getIndex(T value) // получение позиции в списке для заданного значения
    {
        Node* p = head;
        int index = 0;
        while (p != NULL) {
            if (p->value == value) return index;
            p = p->next;
            index++;
        }
        return -1;
    }

    template<typename T> void List<T>::add(T value) // включение нового значения
    {
        Node* p = new Node(value);

        //step = 0;
        if (head != NULL) {
            //step++;
            p->prev = tail;
            tail->next = p;
        }
        else { 
            p->prev = NULL;  
            head = p;
        }

        tail = p;
        size++;
    }

    template<typename T> bool List<T>::add(T value, int index) // включение нового значения в позицию с заданным номером 
    {

        if (!(index >= 0 && index <= size)) return false; // индекс некорректен
        else if (index == size) {
            add(value);
            return true;
        }

        Node* newNode = new Node(value);
        
        /*Node* p;
        if (size >> 1 > index) {
            p = head;
            for (int i = 1; i != index; i++) p = p->next;
        }
        else {
            p = tail;
            for (int i = size; i != index; i--) p = p->prev;
        } // остановились на элементе, который должны подвинуть вправо, чтобы вставить новый на его место*/

        Node* p;
        stepCount = 0;
        if (index <= size - 1 - index) // ближе с головы
        {
            p = head;
            for (int i = 0; i < index; i++) {
                p = p->next;
                stepCount++;
            }
        }
        else // ближе с хвоста
        {
            p = tail;
            for (int i = size - 1; i > index; i--) {
                p = p->prev;
                stepCount++;
            }
        }
        // остановились на элементе, который должны подвинуть вправо, чтобы вставить новый на его место

        if (p == head) {
            newNode->next = p;
            p->prev = newNode;
            head = newNode;
        }
        else {

            p->prev->next = newNode;
            newNode->prev = p->prev;
            newNode->next = p;
            p->prev = newNode;
        }

        size++;
        return true;

        /*
        if (!isNumCorrect(n)) {
            if (n != size + 1) return false; //åñëè íîìåð âíå ðàçìåðíîñòè ñïèñêà è íå ðàâåí (size+1), âîçâðàùàåì false
            else { //åñëè íîìåð = (size+1), âûçûâàåì ìåòîä äîáàâëåíèÿ çàïèñè â êîíåö ñïèñêà
                add(obj);
                return true;
            }
        }
        if (n == 1) { //åñëè íîìåð = 1, äîáàâëÿåì ýëåìåíò â ñàìîå íà÷àëî
            Record* nd = new Record;
            nd->prev = NULL;
            nd->next = first;
            nd->value = obj;
            first->prev = nd;
            first = nd;
            step = 1;
            size++;
            return true;
        }
        Record* tmp = first;
        for (int i = 1; i < n; i++) tmp = tmp->next; // óñòàíàâëèâàåì óêàçàòåëü íà ñëåäóþùèé ýëåìåíò (äî ââåä¸ííîãî íîìåðà)
        Record* ptmp = tmp->prev; //ýëåìåíò, èäóùèé ïåðåä tmp
        Record* nd = new Record; //íîâûé ýëåìåíò
        nd->value = obj;
        if (ptmp != 0 && size != 1) ptmp->next = nd;
        nd->next = tmp;
        nd->prev = ptmp;
        tmp->prev = nd;
        step = n >> 1;
        size++;
        return true;*/
    }

    template<typename T> bool List<T>::remove(T value) {
        
        int index = getIndex(value); // находим индекс нужного элемента
        if (index == -1) return false; // нет такого элемента

        return remove(index, true);

        /*Node p;
        if (size >> 1 > index) {
            p = head;
            for (int i = 1; i != index; i++) p = p->next;
        }
        else {
            p = tail;
            for (int i = size; i != index; i--) p = p->prev;
        } // остановились на элементе, который должны удалить

        if (p == head) {
            head = p->next;
            p->next->prev = NULL;
        }
        else if (p == tail) {
            tail = p->prev;
            p->prev->next = NULL;
        }
        else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }

        delete p;
        size--;
        return true;*/
        
       
        /*step = 0;
        Record* nd = first; //ïðèñâàèâàåì àäðåñ ïåðâîãî ýëåìåíòà
        while (nd != NULL) { //ïîêà nd íå ïóñòîå
            step++;
            if (nd->value == obj) { //ïðîâåðÿåì çíà÷åíèå çàïèñè íà ðàâåíñòâî èñêîìîé çàïèñè
                Record* tn = nd->next;
                Record* tp = nd->prev;
                if (tp == NULL) first = tn; //óäàëÿåìûé áûë ïåðâûì
                if (tn == NULL) last = tp; //óäàëÿåìûé áûë ïîñëåäíèì
                if (tp != NULL) tp->next = tn; //ñóùåñòâóåò ïðåäûäóùèé - óáèðàåì ñâÿçü ñ óäàëÿåìûì
                if (tn != NULL) tn->prev = tp; //ñóùåñòâóåò ñëåäóþùèé - óáèðàåì ñâÿçü ñ óäàëÿåìûì
                delete nd; //î÷èñòêà ïàìÿòè
                size--; //ðàçìåðíîñòü -1
                return true; //âîçâðàò true â ñëó÷àå óñïåõà
            }
            else nd = nd->next; //åñëè çíà÷åíèå íå ðàâíî èñêîìîìó, ïðîäîëæàåì ïåðåáîð
        }
        return false; //âîçâðàò false â ñëó÷àå íåóäà÷è îïåðàöèè óäàëåíèÿ*/
    }

    template<typename T> bool List<T>::remove(int index, bool b) {
        
        if (!(index >= 0 && index < size)) return false;
        if (size == 1) {
            clear();
            return true;
        }

        /*Node p;
        if (size >> 1 > index) {
            p = head;
            for (int i = 1; i != index; i++) p = p->next;
        }
        else {
            p = tail;
            for (int i = size; i != index; i--) p = p->prev;
        } // остановились на элементе, который должны удалить*/

        Node* p;
        stepCount = 0;
        if (index <= size - 1 - index) // ближе с головы
        {
            p = head;
            for (int i = 0; i < index; i++) {
                p = p->next;
                stepCount++;
            }
        }
        else // ближе с хвоста
        {
            p = tail;
            for (int i = size - 1; i > index; i--) {
                p = p->prev;
                stepCount++;
            }
        }
        // остановились на элементе, который должны удалить


        if (p == head) {
            head = p->next;
            p->next->prev = NULL;
        }
        else if (p == tail) {
            tail = p->prev;
            p->prev->next = NULL;
        }
        else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }

        delete p;
        size--;
        return true;
        
        /*step = 0;
        if (!isNumCorrect(n)) return false;
        Record* nd = enumerate(n);
        Record* tn = nd->next;
        Record* tp = nd->prev;
        if (tp == NULL) first = tn; //óäàëÿåìûé áûë ïåðâûì
        if (tn == NULL) last = tp; //óäàëÿåìûé áûë ïîñëåäíèì
        if (tp != NULL) tp->next = tn;//ñóùåñòâóåò ïðåäûäóùèé - óáèðàåì ñâÿçü ñ óäàëÿåìûì
        if (tn != NULL) tn->prev = tp;//ñóùåñòâóåò ñëåäóþùèé - óáèðàåì ñâÿçü ñ óäàëÿåìûì
        delete nd; //î÷èñòêà ïàìÿòè
        size--; //ðàçìåðíîñòü -1
        return true;*/
    }

    template <typename T> void List<T>::show() // вывод списка - it should be in main.cpp
    {
        if (isEmpty()) return;

        Node* p = head;
        do {
            std::cout << p->value << " ::: ";
            p = p->next;
        } while (p != NULL);
        std::cout << std::endl;
        
    }

  
    // обработчики исключений для внешней зоны итератора и проверку для операций при неустановленных итераторах
    // для * и чтения по номеру обработчики исключений

