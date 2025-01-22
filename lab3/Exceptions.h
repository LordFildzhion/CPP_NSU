#ifndef LAB3_EXCEPTIONS_H
#define LAB3_EXCEPTIONS_H

#include <iostream>

namespace Exceptions {

    class AbstrExcp {
    public:
        virtual int errorCode() const = 0;
        virtual ~AbstrExcp() {};
    };

    class CanNotOpenFile : public AbstrExcp {
    public:
        CanNotOpenFile();
        int errorCode() const override;
    };

    class InapropriateFile : public AbstrExcp {
    public:
        InapropriateFile();
        int errorCode() const override;
    };

    class OutOfRange : public AbstrExcp {
    public:
        OutOfRange();
        int errorCode() const override;
    };

    class InapropriateConv : public AbstrExcp {
    public:
        InapropriateConv();
        int errorCode() const override;
    };

    class WrongParameters : public AbstrExcp {
    public:
        WrongParameters();
        int errorCode() const override;
    };

    class WrongComandLineParameters : public AbstrExcp {
    public:
        WrongComandLineParameters();
        int errorCode() const override;
    };

    enum errorCodes {
        CanNotOpenFileCode = 1,
        InapropriateFileCode,
        OutOfRangeCode,
        InapropriateConvCode,
        WrongParametersCode,
        WrongComandLineParametersCode
    };
    
    //canNotOpenFile
    CanNotOpenFile::CanNotOpenFile() {
        std::cerr << "can not open file";
    }

    int CanNotOpenFile::errorCode() const {
        return errorCodes::CanNotOpenFileCode;
    }

    //canNotOpenFile
    InapropriateFile::InapropriateFile() {
        std::cerr << "inapropriate file";
    }

    int InapropriateFile::errorCode() const {
        return errorCodes::InapropriateFileCode;
    }

    //outOfRange
    OutOfRange::OutOfRange() {
        std::cerr << "position is out of range";
    }

    int OutOfRange::errorCode() const {
        return errorCodes::OutOfRangeCode;
    }

    //InapropriateConv
    InapropriateConv::InapropriateConv() {
        std::cerr << "wrong converter is passed";
    }

    int InapropriateConv::errorCode() const {
        return errorCodes::InapropriateConvCode;
    }

    //WrongParameters
    WrongParameters::WrongParameters() {
        std::cerr << "wrong parameters for a converter";
    }

    int WrongParameters::errorCode() const {
        return errorCodes::WrongParametersCode;
    }

    //WrongComandLineParameters
    WrongComandLineParameters::WrongComandLineParameters() {
        std::cerr << "wrong comand line parameters";
    }

    int WrongComandLineParameters::errorCode() const {
        return errorCodes::WrongComandLineParametersCode;
    }

}

#endif //LAB3_EXCEPTIONS_H