O controle de peso de caminhões é uma prática essencial para segurança rodoviária, eficiência logística e preservação das estruturas de transporte. Sistemas de pesagem instalados em transportadoras e postos de fiscalização têm como objetivo garantir que veículos não circulem com excesso de carga, reduzindo riscos de acidentes, danos ao pavimento e desgaste prematuro dos veículos. 

Este trabalho apresenta a construção de uma maquete funcional de pesagem de caminhões, projetada para simular o processo utilizado em postos de controle. O sistema identifica o peso do veículo ao passar sobre uma plataforma dotada de sensores e emite sinais visuais e sonoros conforme faixas preestabelecidas. A maquete busca aproximar conceitos reais de instrumentação industrial, automação e eletrônica, fornecendo uma experiência prática e didática sobre como funcionam sistemas de pesagem no mundo real. 

O sistema de medição é composto por quatro células de carga de três fios, que funcionam como meias-ponte cada uma. Para formar uma ponte de Wheatstone completa, necessária ao funcionamento adequado do módulo HX711, os fios foram conectados da seguinte forma: 
Todos os fios vermelhos das células → E+ do HX711                    
Todos os fios pretos das células → E− do HX711 
Fios brancos das células 1 e 3 (opostas entre si) → A+ 
Fios brancos das células 2 e 4 (opostas entre si) → A− 

Esse arranjo garante leitura diferencial estável e evita cancelamento de sinais. 
O módulo HX711 é responsável por amplificar o sinal dos sensores e enviá-lo ao Arduino Uno, que processa as informações por meio do código desenvolvido. A lógica inclui filtragem de leituras, média de múltiplas amostras e calibração com pesos reais. A saída do sistema é composta por: 
LED RGB (cátodo comum): 
Verde (0,5 a 2 kg) 
Amarelo (2 a 3 kg) 
Vermelho (acima de 3 kg) 
Buzzer: 
1 beep curto quando peso entre 0,5 e 3 kg 
2 beeps rápidos quando peso ultrapassa 3 kg 

Para alimentação, o Arduino foi energizado via USB do computador, garantindo fonte estável e livre de ruídos. Conexões foram reforçadas com solda, termo retrátil e fitas isolantes. 
