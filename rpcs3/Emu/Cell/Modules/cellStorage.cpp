#include "stdafx.h"
#include "Emu/Cell/PPUModule.h"

namespace vm { using namespace ps3; }

extern logs::channel cellSysutil;

enum CellStorageError : u32
{
	CELL_STORAGEDATA_ERROR_BUSY         = 0x8002be01,
	CELL_STORAGEDATA_ERROR_INTERNAL     = 0x8002be02,
	CELL_STORAGEDATA_ERROR_PARAM        = 0x8002be03,
	CELL_STORAGEDATA_ERROR_ACCESS_ERROR = 0x8002be04,
	CELL_STORAGEDATA_ERROR_FAILURE      = 0x8002be05
};

struct CellStorageDataSetParam
{
	be_t<u32> fileSizeMax;
	vm::bptr<char> title;
	vm::bptr<void> reserved;
};

using CellStorageDataFinishCallback = void(s32 result, vm::ptr<void> userdata);

template <>
void fmt_class_string<CellStorageError>::format(std::string& out, u64 arg)
{
	format_enum(out, arg, [](auto error)
	{
		switch (error)
		{
		STR_CASE(CELL_STORAGEDATA_ERROR_ACCESS_ERROR);
		STR_CASE(CELL_STORAGEDATA_ERROR_INTERNAL);
		STR_CASE(CELL_STORAGEDATA_ERROR_PARAM);
		STR_CASE(CELL_STORAGEDATA_ERROR_FAILURE);
		STR_CASE(CELL_STORAGEDATA_ERROR_BUSY);
		}

		return unknown;
	});
}

error_code cellStorageDataImportMove(u32 version, vm::ptr<char> srcMediaFile, vm::ptr<char> dstHddDir, vm::ptr<CellStorageDataSetParam> param, vm::ptr<CellStorageDataFinishCallback> funcFinish, u32 container, vm::ptr<void> userdata)
{
	cellSysutil.todo("cellStorageDataImportMove(version=0x%x, srcMediaFile=%s, dstHddDir=%s, param=*0x%x, funcFinish=*0x%x, container=0x%x, userdata=*0x%x)", version, srcMediaFile, dstHddDir, param, funcFinish, container, userdata);
	return CELL_OK;
}

error_code cellStorageDataImport(u32 version, vm::ptr<char> srcMediaFile, vm::ptr<char> dstHddDir, vm::ptr<CellStorageDataSetParam> param, vm::ptr<CellStorageDataFinishCallback> funcFinish, u32 container, vm::ptr<void> userdata)
{
	cellSysutil.todo("cellStorageDataImport(version=0x%x, srcMediaFile=%s, dstHddDir=%s, param=*0x%x, funcFinish=*0x%x, container=0x%x, userdata=*0x%x)", version, srcMediaFile, dstHddDir, param, funcFinish, container, userdata);
	return CELL_OK;
}

error_code cellStorageDataExport(u32 version, vm::ptr<char> srcHddFile, vm::ptr<char> dstMediaDir, vm::ptr<CellStorageDataSetParam> param, vm::ptr<CellStorageDataFinishCallback> funcFinish, u32 container, vm::ptr<void> userdata)
{
	cellSysutil.todo("cellStorageDataExport(version=0x%x, srcHddFile=%s, dstMediaDir=%s, param=*0x%x, funcFinish=*0x%x, container=0x%x, userdata=*0x%x)", version, srcHddFile, dstMediaDir, param, funcFinish, container, userdata);
	return CELL_OK;
}

void cellSysutil_Storage_init()
{
	REG_FUNC(cellSysutil, cellStorageDataImportMove);
	REG_FUNC(cellSysutil, cellStorageDataImport);
	REG_FUNC(cellSysutil, cellStorageDataExport);
}
