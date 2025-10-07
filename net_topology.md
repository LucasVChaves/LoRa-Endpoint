Origem: LiTel
Data: 03/05/2025
Tópicos: #LoRa #framework #projeto

---

# Topologia da Rede

Estou levando em consideração que utilizaremos o protocolo [LoRaWAN](https://lora-alliance.org/) a topologia é baseada no padrão **star-of-stars**, em que os endpoints se conectam à gateways locais que se comunicam com os servidores, semelhante à telefonia móvel (celular <-> torre <-> provedor).

## Componentes
### Endpoints: 
ESP32 com módulo LoRa (ainda preciso pesquisar modelos possíveis); Sensores dependendo da aplicação local, sensor de umidade e temperatura se for na lavoura por exemplo; Operação em modo Classe A do LoRaWAN (dispositivos iniciam comunicação apenas após envio de dados), otimizando consumo de energia.

### Gateways LoRaWAN: 
Intermediários entre os endpoints e servidores. Podemos fazer alguns endpoints serem gateways também (aumenta custo e gasto de energia). Ideal que sejam colocados em pontos mais altos. Como exemplo, podemos ter um Raspberry Pi com um módulo concentrador LoRa RAK2245.

### Servidor de Rede: 
Pode ser hospedado num Raspberry Pi ou similar com um serviço como [ChirpStack](https://www.chirpstack.io/).

### Servidor de Aplicação: 
Pode rodar no mesmo dispositivo que o de Rede; Utiliza [RabbitMQ](https://www.rabbitmq.com/) ou outro similar como broker para gerenciar as queues de mensagens; Pro banco de dados é possível usar o SQLite que é mais leve, ou um banco de séries temporais como [InfluxDB](https://www.influxdata.com/) (pago); A interface do usuário deve ser um Dashboard, acredito que o melhor seja utilizar [Grafana](https://grafana.com/) e fazer na web.

## Diagrama
![[Rede LoRa 2025-05-03 11.01.09.excalidraw]]

# Considerações
## Segurança
LoRaWAN utiliza chaves de sessão AES-128 e contador de mensagens para evitar replay attacks. Criptografia TLS entre o servidor e broker. Acesso remoto aos Raspberry Pis somente via SSH.

## Escalabilidade
- **Escalabilidade Horizontal**: Adicionar gateways conforme a expansão da área monitorada.
- **Latência**: Calibrar o Spreading Factor para equilibrar alcance e velocidade de transmissão.