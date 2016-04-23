#pragma once
#include "AbstractLayout.h"

namespace wsf
{

	class VerticalLayout :
		public AbstractLayout
	{
	public:
		using Ptr = std::shared_ptr<VerticalLayout>;

		static Ptr create();

		VerticalLayout();
		virtual ~VerticalLayout();

	protected:
		virtual void rearrange();
	};

}
