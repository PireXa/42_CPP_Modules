#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
	this->type = type;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}


