template <class T>
class Set {
private:
    std::set<T> elements;

public:
    void add(const T& element) {
        elements.insert(element);
    }

    void remove(const T& element) {
        elements.erase(element);
    }

    Set<T> intersection(const Set<T>& other) {
        Set<T> result;
        std::set_intersection(elements.begin(), elements.end(), other.elements.begin(), other.elements.end(), std::inserter(result.elements, result.elements.begin()));
        return result;
    }

    Set<T> unionSet(const Set<T>& other) {
        Set<T> result;
        std::set_union(elements.begin(), elements.end(), other.elements.begin(), other.elements.end(), std::inserter(result.elements, result.elements.begin()));
        return result;
    }

    Set<T> difference(const Set<T>& other) {
        Set<T> result;
        std::set_difference(elements.begin(), elements.end(), other.elements.begin(), other.elements.end(), std::inserter(result.elements, result.elements.begin()));
        return result;
    }

    void display() {
        for (const T& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};