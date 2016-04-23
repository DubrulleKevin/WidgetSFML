#ifndef HORIZONTALLAYOUT_H
#define HORIZONTALLAYOUT_H

#include "AbstractLayout.h"

namespace wsf
{

    class HorizontalLayout :
        public AbstractLayout
    {
    public:
		using Ptr = std::shared_ptr<HorizontalLayout>;

		static Ptr create();

		HorizontalLayout();
		virtual ~HorizontalLayout();

	protected:
        virtual void rearrange();
    };

}

#endif // HORIZONTALLAYOUT_H
