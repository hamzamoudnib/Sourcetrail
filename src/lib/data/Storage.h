#ifndef STORAGE_H
#define STORAGE_H

#include <memory>
#include <vector>

#include "data/Graph.h"
#include "data/parser/ParserClient.h"
#include "data/TextLocationFile.h"

class Storage: public ParserClient
{
public:
	Storage();
	virtual ~Storage();

	virtual void onClassParsed(const ParseLocation& location, const std::string& fullName, AccessType access);
	virtual void onStructParsed(const ParseLocation& location, const std::string& fullName, AccessType access);

	virtual void onGlobalVariableParsed(const ParseLocation& location, const ParseVariable& variable);
	virtual void onFieldParsed(const ParseLocation& location, const ParseVariable& variable, AccessType access);

	virtual void onFunctionParsed(
		const ParseLocation& location, const std::string& fullName, const std::string& returnTypeName,
		const std::vector<ParseVariable>& parameters);
	virtual void onMethodParsed(
		const ParseLocation& location, const std::string& fullName, const std::string& returnTypeName,
		const std::vector<ParseVariable>& parameters, AccessType access, AbstractionType abstraction,
		bool isConst, bool isStatic);

	virtual void onNamespaceParsed(const ParseLocation& location, const std::string& fullName);

	virtual void onEnumParsed(const ParseLocation& location, const std::string& fullName, AccessType access);
	virtual void onEnumFieldParsed(const ParseLocation& location, const std::string& fullName);

private:
	void log(std::string type, std::string str, const ParseLocation& location) const;

	Graph m_graph;

	std::vector<std::shared_ptr<TextLocationFile> > m_textLocationFiles;
};

#endif // STORAGE_H
