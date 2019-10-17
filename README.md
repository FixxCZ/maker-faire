<p align="center">
  <img width="20" align="center" src="https://github.com/FixxCZ/maker-faire/blob/master/img/Brno_MMF_Logo.png" alt="logo"/>
</p>
<h1 align="center">Workshop Domací Automatizace</h1>


## Workshop
Po workshopu na Maker Faire vám v rukou zůstal klon [Wemosu D1 mini](https://wiki.wemos.cc/products:d1:d1_mini) a [IR Shield](https://wiki.wemos.cc/products:d1_mini_shields:ir_controller_shield). D1 mini je základním stavebním kamenem pro libovolný chytrý obvod, nebo senzor. Výše najdete zdrojové kódy použité během workshopu.


## Co ted s tím
Pokud máte, nebo začínáte stavět chytrou domácnost, bude ideální použít modul jako IRtoMQTT bránu pomocí [OpenMQTTGateway](https://github.com/1technophile/OpenMQTTGateway). Info o configu [zde](https://github.com/1technophile/OpenMQTTGateway/issues/234).<br>
MQTT server bych doporučoval mít jako součást [Home Assistant](https://www.home-assistant.io/getting-started/). 
##### Upozornění: IR Shield použitý při workshopu má změněný pin pro vysílací diody. Původně se vysílalo na pinu D3, nyní se vysílá na D4. Můžete ho buď přepájet zpět na zadní strane desky, nebo změnit v kodu pro OpenMQTTGateway.


## 📝 Zdroje
[Zigbee to MQTT](https://www.zigbee2mqtt.io/) Další výborná brána, ale vyžaduje specialní USB dongle s nahraným firmwarem. Budu prodávat pár předprogramovaných kousků za lidovou cenu.
[OpenMQTTGateway](https://github.com/1technophile/OpenMQTTGateway) Mimo IR podporuje i RF což je ještě zajímavější.


