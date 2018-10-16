// Copyright 2001-2018 Crytek GmbH. All rights reserved.
#pragma once

#include "IFilesGroupProvider.h"
#include "CryString/CryString.h"
#include <vector>

class CAsset;

class CAssetFilesGroupProvider : public IFilesGroupProvider
{
public:
	CAssetFilesGroupProvider(CAsset* pAsset, bool shouldIncludeSourceFile)
		: m_pAsset(pAsset)
		, m_metadata(pAsset->GetMetadataFile())
		, m_name(pAsset->GetName())
		, m_shouldIncludeSourceFile(shouldIncludeSourceFile)
	{}

	virtual std::vector<string> GetFiles(bool includeGeneratedFile = true) const override final;

	virtual const string& GetName() const override final { return m_name; }

	virtual const string& GetMainFile() const override final { return m_metadata; }

	virtual string GetGeneratedFile() const override final;

	virtual void Update() override final;

private:
	CAsset* m_pAsset;
	string  m_metadata;
	string  m_name;
	bool    m_shouldIncludeSourceFile;
};
