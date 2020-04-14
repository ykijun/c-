// SUBMIT THIS FILE

template<typename K, typename V>
Dictionary<K,V>::Dictionary(const Dictionary& another){
		this->size = another.getSize();
		this->array = new KeyValue[size];
		for (int i = 0; i < size; i++){
			array[i] = {another.array[i].key, another.array[i].value};
		}

}


template<typename K, typename V>
V& Dictionary<K,V>::operator[](K key){
	for (int i = 0; i < size; i++){
		if (this->array[i].key == key){
				return array[i].value;
		}
	}
	size++;
	KeyValue *array2 = new KeyValue[size];
	for (int j = 0; j< size - 1; j ++){
		array2[j] = {this->array[j].key, this->array[j].value};
	}
	array2[size-1]= {key,0};
	delete[] array;
	array = array2;
	return array[size-1].value;

}


template<typename K, typename V>
Dictionary<K,V>& Dictionary<K,V>::operator=(const Dictionary& another){
	if (this != &another){
		this->size = another.getSize();
		this->array = new KeyValue[size];
		K* keylist = another.getKeyList();
		V* vlist = another.getValueList();
		for (int i = 0; i < size; i++){
			this->array[i] = {keylist[i], vlist[i]};
		}
		delete[] keylist;
		delete[] vlist;
		return *this;
	}
	else return *this;
}




template<typename K, typename V>
K* Dictionary<K,V>::getKeyList() const{
	if (this->array == NULL){
		return NULL;
	}
	K* keylist = new K[size];
	for (int i = 0 ; i < size; i++){
		keylist[i] = this->array[i].key;
	}
	return keylist;
}


template<typename K, typename V>
V* Dictionary<K,V>::getValueList() const{
	if (this->array == NULL){
		return NULL;
	}
	V* valuelist = new V[size];
	for (int i = 0 ; i < size; i++){
		valuelist[i] = this->array[i].value;
	}
	return valuelist;


}


template<typename K, typename V>
void Dictionary<K,V>::clean(){
	this->size = 0;
	delete[] array;
	this->array = NULL;
}


