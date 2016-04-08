#ifndef QUERYWITHPOINTER_H
#define QUERYWITHPOINTER_H

#include "TextQuery.h"
#include <memory>
#include "Query_base.h"

class QueryPoint
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	QueryPoint(const std::string&);
	QueryResult eval(const TextQuery &t)const
	{
		return q->eval(t);
	}

	QueryPoint(const QueryPoint &base) :q(new Query_base(*(base->q)))
	{}

	QueryPoint& operator=(const QueryPoint& point)
	{
		if (this != &point)
		{
			Query_base* temp = new Query_base(*point);
			delete q;
			q = temp;
		}
		reuturn *this
	}
	virtual ~QueryPoint_base()
	{
		delete q;
		q = nullptr;
	}
	std::string rep()const { return q->rep(); }
private:
	QueryPoint_base(Query_base* query) :q(new Query_base(*query){}
	Query_base* q;
};

class WordQueryPoint :public Query_base
{
	friend class QueryPoint;
	WordQuery(const std::string &s) :query_word(s){}
	QueryResult eval(const TextQuery &t) const override{ return t.query(query_word); }
	std::string rep() const override{ return query_word; }
	std::string query_word;
};
inline Query::Query(const std::string &s) : q(new WordQuery(s)){ }
#endif