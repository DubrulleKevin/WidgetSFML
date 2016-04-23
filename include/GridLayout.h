#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include <AbstractLayout.h>

namespace wsf
{

    class GridLayout :
		public AbstractLayout
    {
    public:
        
		using Ptr = std::shared_ptr<GridLayout>;

		static Ptr create(const unsigned int argRows, const unsigned int argCols);

        virtual void addWidget(AbstractWidget::Ptr widget);

		GridLayout(const unsigned int argRows, const unsigned int argCols);
		virtual ~GridLayout();

	protected:
        virtual void rearrange();

    private:
        unsigned int rows;
        unsigned int cols;
    };

}

#endif // GRIDLAYOUT_H
