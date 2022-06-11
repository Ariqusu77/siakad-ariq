#include <iostream>
#include <vector>

#include "include/dosen.hpp"
#include "include/mahasiswa.hpp"
#include "include/matkul.hpp"
#include "include/person.hpp"
#include "include/tendik.hpp"

int main(){

    std::vector<mahasiswa> recmhs;
    std::vector<dosen> recdsn;
    std::vector<tendik> rectdk;
    std::vector<matkul> recmtk;

    while (1)
    {
        std::cout << "========== welcome ===========" << std::endl << std::endl;
        int i;
        std::cout << "pilihan menu :" << std::endl;
        std::cout << "1. tambahkan mahasiswa" << std::endl;
        std::cout << "2. tambahkan dosen" << std::endl;
        std::cout << "3. tambahkan tendik" << std::endl;
        std::cout << "4. tampilkan mahasiswa" << std::endl;
        std::cout << "5. tampilkan dosen" << std::endl;
        std::cout << "6. tampilkan tendik" << std::endl;

        std::cout << "silahkan pilih :" << std::endl;
        std::cin >> i;

        switch (i)
        {
        case 1:
            {
                if(recdsn.size() != 0){
                    
				    std::string IdMhs,NmMhs,NrpMhs,DepMhs;
				    int DdMhs,MmMhs,YyMhs,TmMhs;

			    	std::cout << std::endl << "masukkan identitas mahasiswa     : " ; std::cin >> IdMhs;
			    	std::cout << "masukkan nama mahasiswa          : " ; std::cin.ignore(); getline(std::cin,NmMhs);
		    		std::cout << "masukkan tanggal lahir mahasiswa : " ; scanf("%i %i %i",&DdMhs,&MmMhs,&YyMhs);
		    		std::cout << "masukkan nrp mahasiswa           : " ; std::cin >> NrpMhs;
		    		std::cout << "masukkan departemen mahasiswa    : " ; std::cin.ignore(); getline(std::cin,DepMhs);
		    		std::cout << "masukkan tahun masuk mahasiswa   : " ; std::cin >> TmMhs;
                    mahasiswa Mhssem(IdMhs,NmMhs,DdMhs,MmMhs,YyMhs,NrpMhs,DepMhs,TmMhs);

                    int n=1;
                    while(n==1)
                    {   
                        int pilih;
                        std::cout << std::endl << "silahkan pilih matkul untuk diambil :" << std::endl;
                        std::cout << "(anda memiliki " << Mhssem.getskssemester() << " sisa sks)" << std::endl;
                        for(unsigned int i = 0; i<recmtk.size();i++)
                        {
                            std::cout << i+1 << ". " << recmtk[i].getjudul() << std::endl;
                        }
                        std::cin >> pilih;
                        Mhssem.matkulsemester.push_back(recmtk[pilih]);
                        int temp = Mhssem.getskssemester() - recmtk[pilih].getbobotsks();
                        Mhssem.setskssemester(temp);
                    }  
                    
		    		recmhs.push_back(Mhssem);
			
                }else{
                    std::cout << "mahasiswa tidak bisa ditambahkan karena tidak ada tenaga pengajar" << std::endl;
                }
            }
            break;

        case 2:
            {
                std::string IdDsn,NmDsn,NppDsn,DepDsn,MtkDsn;
				int DdDsn,MmDsn,YyDsn,PdDsn,BbtDsn;

				std::cout << std::endl << "masukkan identitas dosen     : " ; std::cin >> IdDsn;
				std::cout << "masukkan nama dosen          : " ; std::cin.ignore(); getline(std::cin,NmDsn);
				std::cout << "masukkan tanggal lahir dosen : " ; scanf("%i %i %i",&DdDsn,&MmDsn,&YyDsn);
				std::cout << "masukkan npp dosen           : " ; std::cin >> NppDsn;
				std::cout << "masukkan departemen dosen    : " ; std::cin.ignore(); getline(std::cin,DepDsn);
				std::cout << "masukkan Pendidikan dosen    : " ; std::cin >> PdDsn;
                std::cout << "masukkan matkul yang diampu  : " ; std::cin.ignore(); getline(std::cin,MtkDsn);
                std::cout << "masukkan bobot matkul        : " ; std::cin >> BbtDsn;

				dosen Dsnsem(IdDsn,NmDsn,DdDsn,MmDsn,YyDsn,NppDsn,DepDsn,PdDsn);
                Dsnsem.matkuldiampu.setjudul(MtkDsn);
                Dsnsem.matkuldiampu.setbobotsks(BbtDsn);
                matkul Mtksem(BbtDsn,MtkDsn);
				recdsn.push_back(Dsnsem);
                recmtk.push_back(Mtksem);
            }
            break;

        case 3:
            {
                std::string IdTpd,NmTpd,NppTpd,UnTpd;
				int DdTpd,MmTpd,YyTpd;

				std::cout << std::endl << "masukkan identitas tendik     : " ; std::cin >> IdTpd;
				std::cout << "masukkan nama tendik          : " ; std::cin.ignore(); getline(std::cin,NmTpd);
				std::cout << "masukkan tanggal lahir tendik : " ; scanf("%i %i %i",&DdTpd,&MmTpd,&YyTpd);
				std::cout << "masukkan npp tendik           : " ; std::cin >> NppTpd;
				std::cout << "masukkan departemen tendik    : " ; std::cin.ignore(); getline(std::cin,UnTpd);

				tendik Tdksem(IdTpd,NmTpd,DdTpd,MmTpd,YyTpd,NppTpd,UnTpd);
				rectdk.push_back(Tdksem);
            }
            break;

        case 4:
            {
                for (unsigned int i = 0; i < recmhs.size(); i++)
				{
					std::cout << "identitas mahasiswa     : " << recmhs[i].getId()   << std::endl;
					std::cout << "nama mahasiswa          : " << recmhs[i].getNama() << std::endl;
					std::cout << "tanggal lahir mahasiswa : " << recmhs[i].getTglLahir() << "\\" << recmhs[i].getBulanLahir() << "\\" << recmhs[i].getTahunLahir() << std::endl; 
					std::cout << "nrp mahasiswa           : " << recmhs[i].getNRP() << std::endl;
					std::cout << "departemen mahasiswa    : " << recmhs[i].getDepartemen() << std::endl;
					std::cout << "tahun masuk mahasiswa   : " << recmhs[i].getTahunmasuk() << std::endl;
                    std::cout << "matkul mahasiswa        : " << std::endl;
                    for (unsigned int i = 0; i < recmhs[i].matkulsemester.size() ; i++)
                    {
                        std::cout << i+1 << ". " << recmhs[i].matkulsemester[i].getjudul() << std::endl;
                    }   
				}
            }
            break;

        case 5:
            {
                for (unsigned int i = 0; i < recdsn.size(); i++)
				{
					std::cout << "identitas dosen     : " << recdsn[i].getId() << std::endl;
					std::cout << "nama dosen          : " << recdsn[i].getNama() << std::endl;
					std::cout << "tanggal lahir dosen : " << recdsn[i].getTglLahir() << "\\" << recdsn[i].getBulanLahir() << "\\" << recdsn[i].getTahunLahir() << std::endl; 
					std::cout << "npp dosen           : " << recdsn[i].getnpp() << std::abort;
					std::cout << "departemen dosen    : " << recdsn[i].getDepartemen() << std::endl;
					std::cout << "Pendidikan dosen    : " << recdsn[i].getPendidikan() << std::endl;
                    std::cout << "matkul diampu dosen : " << recdsn[i].matkuldiampu.getjudul() << std::endl;
				}
            }
            break;

        case 6:
            {
                for (unsigned int i = 0; i < rectdk.size(); i++)
				{
					std::cout << "identitas tenaga pendidik     : " << rectdk[i].getId()  << std::endl;
					std::cout << "nama tenaga pendidik          : " << rectdk[i].getNama() << std::endl;
					std::cout << "tanggal lahir tenaga pendidik : " << rectdk[i].getTglLahir() << "\\" << rectdk[i].getBulanLahir() << "\\" << rectdk[i].getTahunLahir() << std::endl; 
					std::cout << "npp tenaga pendidik           : " << rectdk[i].getNPP() << std::endl;
					std::cout << "unit tenaga pendidik          : " << rectdk[i].getUnit() << std::endl;
				}
            }
            break;
        
        default:
            break;
        }
    }
    
}