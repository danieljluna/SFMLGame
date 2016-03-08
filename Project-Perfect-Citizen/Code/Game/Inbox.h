#pragma once

#include <vector>
#include <string>
#include "Email.h"

///////////////////////////////////////////////////////////////////////
/// @author Alex Vincent
/// @brief A singleton structure to a desktop that contains emails
/// @details Contains a vector of emails to which can be added to
/// the email application on the desktop
///////////////////////////////////////////////////////////////////////

namespace ppc {

	class Inbox {

	public:

		///////////////////////////////////////////////////////////////////////
		///@brief Default constructor
		///////////////////////////////////////////////////////////////////////
		Inbox();

		///////////////////////////////////////////////////////////////////
		// ACCESSORS
		///////////////////////////////////////////////////////////////////
		bool isEmpty();

		ppc::Email getEmailAt(int position);

		int getInboxSize();

		///////////////////////////////////////////////////////////////////
		// MUTATORS
		///////////////////////////////////////////////////////////////////

		void addEmailToList(ppc::Email email);

		void removeEmailFromList(int position);

	protected:
		std::vector<ppc::Email> messageList;
	};

}