import numpy as np
from typing import List, Union, Tuple
import pandas as pd



def test_performance(func):
    def wrapper(*args, **kwargs):
        import time
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"Function '{func.__name__}' executed in {end_time - start_time:.4f} seconds.")
        return result
    return wrapper



class Tokenizer:    

    """A simple tokenizer that converts text into token IDs based on a generated vocabulary."""
    def __init__(self):
        self.tokenizer = {
            "<PAD>": 0,
            "<UNK>": 1,
            "<CLS>":  2
        }
        self.vocab_size = 0
        self.is_fitted = False
    
    
   
    
    
    def save_tokenizer(self, filepath: str):
        """
        Docstring for save_tokenizer
        
        :param self: save the tokenizer
        :param filepath: the filename and path that we want to use for a tokenizer
        :type filepath: str
        """
        pd.DataFrame.from_dict(self.tokenizer, orient='index').to_csv(filepath, header=False)
    
    def load_tokenizer(self, filepath: str):
        """
        Docstring for load_tokenizer
        
        :param self: load a tokenizer already made
        :param filepath: path of the tokenizer, only support csv file
        :type filepath: str
        """
        df = pd.read_csv(filepath, header=None, index_col=0)
        self.tokenizer = df[1].to_dict()
        self.vocab_size = len(self.tokenizer)

    @test_performance
    def encode(self, data: Union[str, List[str]], max_seq_len:int = 100) -> Tuple[List[np.ndarray], List[np.ndarray]]:
        """
        
        """
        mask_list = []
        tokenized_data = []
        if isinstance(data,(list,np.ndarray)):
            for sentence in data:
                sentence = "<CLS> " + sentence
                sentence_array = []
                if isinstance(sentence,str):
                    for word in sentence.split()[0:max_seq_len - 1]:
                        sentence_array.append(self.tokenizer.get(word, 1))  
                    #gère les chaines trop courtes
                    if len(sentence_array) < max_seq_len:
                        while len(sentence_array) < max_seq_len:
                            sentence_array.append(self.tokenizer["<PAD>"])
                sentence_array = np.array(sentence_array)
                mask = np.array([0 if value == 0 else 1 for value in sentence_array])
                mask_list.append(mask)
                tokenized_data.append(sentence_array)
        elif isinstance(data,str):
            raise RuntimeError("In preparation but does not actually support string")
        return tokenized_data, mask_list
    


    @test_performance
    def fit(self, data: Union[str, List[str]]) -> Union[dict[str, int],str]:
        """
        Docstring for fit 
        
        :param self: 
        :param data: a string or a list of string
        :type data: Union[str, List[str]]
        :return: a list of words that correspond with a number
        :rtype: dict[str, int]
        """
        if not self.is_fitted:
            self.is_fitted = True
            if isinstance(data,(list, np.ndarray)):
                for sentence in data:
                    self._create_token(sentence)
            elif isinstance(data,str):
                if data.endswith(".txt"):
                    with open(data, mode = "r+", encoding= "utf-8") as file:
                        data = file.readlines()
                self._create_token(data)
            self.vocab_size = len(self.tokenizer)
            return self.tokenizer
        else:
            raise RuntimeError("Tokenizer already built")


    def _create_token(self,sentences:Union[list[str],str]) -> dict[str, str]:
        """
        Docstring for _create_token
        
        :param self: Description
        :param sentences: Description
        :type sentences: str
        :return: Description
        :rtype: dict[str, str]
        """
        if isinstance(sentences, str):
            for token in sentences.split():
                if token not in self.tokenizer:
                    self._update_vocab(token)
        elif isinstance(sentences, list):
            for token in sentences:
                self._create_token(token)
        return self.tokenizer
    
    

    def _update_vocab(self, word)-> None:
        self.tokenizer[word] = len(self.tokenizer) + 1





