#ifndef BLOOM_H
#define BLOOM_H

#include <stdbool.h>
#include <stddef.h>

 //Estrutura que representa um Filtro de Bloom.
 //v_bits   : vetor de bits onde os elementos são armazenados.
 //tam_bits : quantidade total de bits do vetor (m).
 //num_hash : quantidade de funções hash utilizadas (k).
typedef struct {
    unsigned char *v_bits;
    size_t tam_bits;
    size_t num_hash;
} filtrobloom;

//Cria um novo Filtro de Bloom.
filtrobloom *criar(size_t n, double p);

//Libera toda a memória utilizada pelo filtro.
 
void destruir(filtrobloom *filtro);

//Insere um elemento no filtro.

void inserir(filtrobloom *filtro, const char *texto);

//Consulta um elemento.
//true -> provavelmente pertence ao conjunto.
//false -> certamente não pertence.
 
bool consultar(filtrobloom *filtro, const char *texto);

//Mede experimentalmente a taxa de falsos positivos.
//Retorna a taxa de falsos positivos encontrada.

double medir_falsos_positivos(
    filtrobloom *filtro,
    const char *elementos[],
    size_t quantidade);

#endif
