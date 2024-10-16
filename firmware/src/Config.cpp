#include "Config.h"

// WiFi credentials
// use this for enterprise networks
const char *EAP_IDENTITY = "username@city.ac.uk";
const char *EAP_USERNAME = "username@city.ac.uk";
const char *EAP_PASSWORD = "password";
const char *ssid = "eduroam";
// use this for personal networks
const char *ssid_peronal = "SKYCFZHN-2.4G";
const char *password_personal = "CFaxCbZ9Y6CQ";

// WebSocket server details
const char *websocket_server = "192.168.0.30";
const uint16_t websocket_port = 8000;
const char *websocket_path = "/starmoon";
const char *auth_token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyX2lkIjoiNWFmNjJiMGUtM2RhNC00YzQ0LWFkZjctNWIxYjdjOWM0Y2I2IiwiZW1haWwiOiJhZG1pbkBzdGFybW9vbi5hcHAiLCJpYXQiOjE3Mjg4NTM2NDV9._rDGYrhDFn4GWLIT5MZtdOFNmDmAtZalKpI8wl_qYzs";

// I2S and Audio parameters
const uint32_t SAMPLE_RATE = 16000;
const int bufferCnt = 20;
const int bufferLen = 1024;
const int I2S_READ_LEN = 1024;
int16_t sBuffer[bufferLen];

// ----------------- Pin Definitions -----------------

#ifdef USE_NORMAL_ESP32
// XIAO ESP32 pins
const int I2S_SD = 13;
const int I2S_WS = 5;
const int I2S_SCK = 18;
const i2s_port_t I2S_PORT_IN = I2S_NUM_0;

const int I2S_WS_OUT = 32;
const int I2S_BCK_OUT = 33;
const int I2S_DATA_OUT = 25;
const i2s_port_t I2S_PORT_OUT = I2S_NUM_1;
const int I2S_SD_OUT = -1;

const int BUTTON_PIN = 26;

#elif defined(USE_XIAO_ESP32)
// Normal ESP32 pins
const int I2S_SD = D9;
const int I2S_WS = D8;
const int I2S_SCK = D7;
const i2s_port_t I2S_PORT_IN = I2S_NUM_0;

const int I2S_WS_OUT = D0;
const int I2S_BCK_OUT = D1;
const int I2S_DATA_OUT = D2;
const i2s_port_t I2S_PORT_OUT = I2S_NUM_1;
const int I2S_SD_OUT = D3;

const int BUTTON_PIN = D5;
#endif

// SSL certificate
const char *rootCACertificate = "-----BEGIN CERTIFICATE-----\n"
                                "MIIFBjCCAu6gAwIBAgIRAIp9PhPWLzDvI4a9KQdrNPgwDQYJKoZIhvcNAQELBQAw\n"
                                "TzELMAkGA1UEBhMCVVMxKTAnBgNVBAoTIEludGVybmV0IFNlY3VyaXR5IFJlc2Vh\n"
                                "cmNoIEdyb3VwMRUwEwYDVQQDEwxJU1JHIFJvb3QgWDEwHhcNMjQwMzEzMDAwMDAw\n"
                                "WhcNMjcwMzEyMjM1OTU5WjAzMQswCQYDVQQGEwJVUzEWMBQGA1UEChMNTGV0J3Mg\n"
                                "RW5jcnlwdDEMMAoGA1UEAxMDUjExMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n"
                                "CgKCAQEAuoe8XBsAOcvKCs3UZxD5ATylTqVhyybKUvsVAbe5KPUoHu0nsyQYOWcJ\n"
                                "DAjs4DqwO3cOvfPlOVRBDE6uQdaZdN5R2+97/1i9qLcT9t4x1fJyyXJqC4N0lZxG\n"
                                "AGQUmfOx2SLZzaiSqhwmej/+71gFewiVgdtxD4774zEJuwm+UE1fj5F2PVqdnoPy\n"
                                "6cRms+EGZkNIGIBloDcYmpuEMpexsr3E+BUAnSeI++JjF5ZsmydnS8TbKF5pwnnw\n"
                                "SVzgJFDhxLyhBax7QG0AtMJBP6dYuC/FXJuluwme8f7rsIU5/agK70XEeOtlKsLP\n"
                                "Xzze41xNG/cLJyuqC0J3U095ah2H2QIDAQABo4H4MIH1MA4GA1UdDwEB/wQEAwIB\n"
                                "hjAdBgNVHSUEFjAUBggrBgEFBQcDAgYIKwYBBQUHAwEwEgYDVR0TAQH/BAgwBgEB\n"
                                "/wIBADAdBgNVHQ4EFgQUxc9GpOr0w8B6bJXELbBeki8m47kwHwYDVR0jBBgwFoAU\n"
                                "ebRZ5nu25eQBc4AIiMgaWPbpm24wMgYIKwYBBQUHAQEEJjAkMCIGCCsGAQUFBzAC\n"
                                "hhZodHRwOi8veDEuaS5sZW5jci5vcmcvMBMGA1UdIAQMMAowCAYGZ4EMAQIBMCcG\n"
                                "A1UdHwQgMB4wHKAaoBiGFmh0dHA6Ly94MS5jLmxlbmNyLm9yZy8wDQYJKoZIhvcN\n"
                                "AQELBQADggIBAE7iiV0KAxyQOND1H/lxXPjDj7I3iHpvsCUf7b632IYGjukJhM1y\n"
                                "v4Hz/MrPU0jtvfZpQtSlET41yBOykh0FX+ou1Nj4ScOt9ZmWnO8m2OG0JAtIIE38\n"
                                "01S0qcYhyOE2G/93ZCkXufBL713qzXnQv5C/viOykNpKqUgxdKlEC+Hi9i2DcaR1\n"
                                "e9KUwQUZRhy5j/PEdEglKg3l9dtD4tuTm7kZtB8v32oOjzHTYw+7KdzdZiw/sBtn\n"
                                "UfhBPORNuay4pJxmY/WrhSMdzFO2q3Gu3MUBcdo27goYKjL9CTF8j/Zz55yctUoV\n"
                                "aneCWs/ajUX+HypkBTA+c8LGDLnWO2NKq0YD/pnARkAnYGPfUDoHR9gVSp/qRx+Z\n"
                                "WghiDLZsMwhN1zjtSC0uBWiugF3vTNzYIEFfaPG7Ws3jDrAMMYebQ95JQ+HIBD/R\n"
                                "PBuHRTBpqKlyDnkSHDHYPiNX3adPoPAcgdF3H2/W0rmoswMWgTlLn1Wu0mrks7/q\n"
                                "pdWfS6PJ1jty80r2VKsM/Dj3YIDfbjXKdaFU5C+8bhfJGqU3taKauuz0wHVGT3eo\n"
                                "6FlWkWYtbt4pgdamlwVeZEW+LM7qZEJEsMNPrfC03APKmZsJgpWCDWOKZvkZcvjV\n"
                                "uYkQ4omYCTX5ohy+knMjdOmdH9c7SpqEWBDC86fiNex+O0XOMEZSa8DA\n"
                                "-----END CERTIFICATE-----\n"
                                "";