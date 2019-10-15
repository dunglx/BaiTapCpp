/* Muc tieu:
  -  Lam quen voi cach xu ly, thao tac lien quan toi web server thong qua thu vien Curl
  -  Lam cac bai tap duoc chia nho tu bai toan OTA lon
*/

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  char * buffer;
  long lSize;
  size_t result;

  FILE* f = fopen("test.xml", "rb");
  if (f==NULL) std::cout << "Khong mo dc file" << std::endl;
  else
    {
	  fseek(f, 0, SEEK_END);
	  lSize = ftell(f);
	  rewind (f);
      buffer = (char*) malloc(sizeof(char)*lSize);
      if(buffer==NULL) std::cout << "Khong co noi dung" << std::endl;
      result = fread(buffer,1,lSize,f);
      if (result != lSize) std::cout << "Doc loi" << std::endl;

	  fclose(f);
	  free(buffer);
	}

  std::cout << buffer << std::endl;
  struct curl_slist *headers=NULL;
  headers = curl_slist_append(headers, "\"Content-Type:text/xml;charset=UTF-8"\");  

  curl = curl_easy_init();
  if(curl) {
    //curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buffer);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_URL, "http://ota.bphone.bkav.com/service/update2");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    std::cout << readBuffer << std::endl;
  }
  return 0;
}
