#ifndef LAB3_CONVERTER_H
#define LAB3_CONVERTER_H

#include <map>


#include "WAVEdit.h"
#include "Consts.h"
#include "Exceptions.h"


using WAV::WAVFiles;

namespace Converters {
    struct ConvArgs {
        std::string name;
        WAVFiles files;
        Times times;
    };

    class AbstrConv {
    public:
        virtual void makeChanges(samples) = 0;
        virtual bool checkInput(ConvArgs) = 0;
        virtual ~AbstrConv() {};
        virtual void info() = 0;

    private:
    };

    class Mute : public AbstrConv {
    public:
        virtual void makeChanges(samples) override;
        virtual bool checkInput(ConvArgs) override;
        virtual void info() override;

    private:
        int numOfFiles = 0;
        int numOfTimePoints = 2;
    };

    class Mix : public AbstrConv {
    public:
        virtual void makeChanges(samples) override;
        virtual bool checkInput(ConvArgs) override;
        virtual void info() override;

    private:
        int numOfFiles = 1;
        int numOfTimePoints = 1;
    };

    class Overlap : public AbstrConv {
    public:
        virtual void makeChanges(samples) override;
        virtual bool checkInput(ConvArgs) override;
        virtual void info() override;

    private:
        int numOfFiles = 1;
        int numOfTimePoints = 1;
    };

    class AbstrCreator {
    public:
        virtual AbstrConv*  createConv() = 0;
    };

    template <class T>
    class Creator : public AbstrCreator {
    public:
        virtual AbstrConv* createConv() override {
            return new(T);
        }
    };

    static std::map<std::string, AbstrCreator*> factories = {
            { {"mute", new Creator<Mute>},
              {"mix", new Creator<Mix>},
              {"overlap", new Creator<Overlap>}}
    };

    static std::map<std::string, AbstrConv*> converters = {
            { {"mute", new Mute},
              {"mix", new Mix},
              {"overlap", new Overlap}}
    };

    AbstrConv* createConverter(std::string name);
}

namespace Converters {
    AbstrConv* createConverter(std::string name) {
        if (factories.find(name) == factories.end()) {
            throw Exceptions::InapropriateConv();
        }

        return factories[name]->createConv();
    }

    //mute
    void Mute::makeChanges(samples smpls) {
        short* sample = smpls[0];
        for (int i = 0; i < Consts::samplesInSec; ++i) {
            sample[i] = Consts::zeroValue;
        }
    }

    bool Mute::checkInput(ConvArgs args) {
        return args.files.size() == numOfFiles && args.times.size() == numOfTimePoints;
    }

    void Mute::info() {
        std::cout << "mute:\n";
        std::cout << "mutes passed interval\n";
        std::cout << "this parameters must be past:\n";
        std::cout << "files: " << numOfFiles << ", timePoints: " << numOfTimePoints << '\n';
        std::cout << '\n';
    }

    //mix
    void Mix::makeChanges(samples smpls) {
        short* sample = smpls[0], *otherSample = smpls[1];
        for (int i = 0; i < Consts::samplesInSec; ++i) {
            sample[i] = (sample[i] + otherSample[i])/2;
        }
    }

    bool Mix::checkInput(ConvArgs args) {
        return args.files.size() == numOfFiles && args.times.size() == numOfTimePoints;
    }

    void Mix::info() {
        std::cout << "mix:\n";
        std::cout << "takes two files and mixes them - takes average sample\n";
        std::cout << "begining from passed timepoint and ending by the end of one of the files\n";
        std::cout << "this parameters must be past:\n";
        std::cout << "files: " << numOfFiles << ", timePoints: " << numOfTimePoints << '\n';
        std::cout << '\n';
    }

    //Overlap
    void Overlap::makeChanges(samples smpls) {
        short* sample = smpls[0], * otherSample = smpls[1];
        for (int i = 0; i < Consts::samplesInSec; ++i) {
            sample[i] = otherSample[i];
        }
    }

    bool Overlap::checkInput(ConvArgs args) {
        return args.files.size() == numOfFiles && args.times.size() == numOfTimePoints;
    }

    void Overlap::info() {
        std::cout << "overlap:\n";
        std::cout << "overlaps one file by another file - changes file's samples by another's\n";
        std::cout << "begining from passed timepoint and ending by the end of one of the files\n";
        std::cout << "this parameters must be past:\n";
        std::cout << "files: " << numOfFiles << ", timePoints: " << numOfTimePoints << '\n';
        std::cout << '\n';
    }
}

#endif //LAB3_CONVERTER_H
