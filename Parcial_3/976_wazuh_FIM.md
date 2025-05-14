# Reporte de Actividad 976 wazuh como FIM y detectar datos de tarjeta
## Kenny Yaritza Benitez Renteral | 210300510  
14/05/2025  

El objetivo de esta prueba de concepto fue implementar un sistema de monitoreo de integridad de archivos (FIM) con Wazuh y detectar posibles registros o accesos a datos sensibles como tarjetas de crédito, lo cual es fundamental para cumplir con normativas como PCI-DSS en entornos reales.

### Para ello, decidi utilizar:

- Docker, para desplegar la infraestructura rápidamente.
- Wazuh como servidor y dashboard, para actuar como sistema de monitoreo.
- Ubuntu Desktop en máquina virtual, como sistema operativo base.
- Archivo simulado con datos de tarjeta, para comprobar las reglas de detección de Wazuh.

### Pasos:

#### 1. Clonar el repositorio oficial de Wazuh en Docker

Se utilizó el siguiente repositorio oficial para el despliegue de Wazuh con Docker:

```bash
git clone https://github.com/wazuh/wazuh-docker.git
cd wazuh-docker/single-node
````

#### 2. Desplegar Wazuh

Con los archivos de Docker Compose proporcionados por el repositorio, se ejecutó:

```bash
docker-compose -f generate-indexer-certs.yml run --rm generator
docker-compose up -d
```

Este proceso inicia los contenedores necesarios para Wazuh: `wazuh.manager`, `wazuh.indexer`, `wazuh.dashboard` y `wazuh.agent`.

Una vez levantado pude conectar al portal de login por me dio de: `https://localhost:5601`

Sin embargo, aun que los contenedores se levantaron correctamente y los servicios estaban activos, al intentar iniciar sesión en el dashboard con las credenciales por defecto (`admin` / `admin`) se presentaba un error de autenticación.

Debido a esoo se Modifico el archivo `wazuh_users.yml` para intentar cambiar la contraseña del usuario admin, se busco y edito variables de entorno relacionadas en el `docker-compose.yml`, asi como se revisaron los logs dentro de los contenedores.
Al no obtener un progreso se elimino y se volvio a crear cada uno de los contenedores, así como regenerar los certificados.
Como ultima opción se cambio la configuración interna de algunso archios como `internal_users.yml` y `roles.yml`.


Ninguna de las modificaciones permitió el acceso exitoso al dashboard. Al parecer, las credenciales estaban encriptadas y gestionadas desde el contenedor del indexador, por lo que una simple edición de los archivos YAML no era suficiente sin regenerar o sincronizar adecuadamente los certificados y contraseñas.

Se espera poder:

* Configurar correctamente el acceso inicial desde el contenedor del indexador.
* Utilizar scripts de reseteo de contraseña recomendados por la comunidad Wazuh.
* Probar las reglas personalizadas para la detección de patrones tipo tarjeta como:

  ```regex
  \b(?:\d[ -]*?){13,16}\b
  ```

