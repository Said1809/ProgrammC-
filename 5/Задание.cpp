int main() {
    Set<int> set1, set2;
    
    set1.add(1);
    set1.add(2);
    set1.add(3);

    set2.add(3);
    set2.add(4);
    set2.add(5);

    Set<int> intersectionSet = set1.intersection(set2);
    Set<int> unionSet = set1.unionSet(set2);
    Set<int> differenceSet = set1.difference(set2);

    std::cout << "Set 1: ";
    set1.display();
    std::cout << "Set 2: ";
    set2.display();
    std::cout << "Intersection set: ";
    intersectionSet.display();
    std::cout << "Union set: ";
    unionSet.display();
    std::cout << "Difference set: ";
    differenceSet.display();

    return 0;
}