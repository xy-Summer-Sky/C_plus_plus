FirstC++APP/
│
├── include/          # 头文件目录
│   ├── database/     # 数据库交互相关的类
│   │   ├── dbmanager.h
│   │   └── querymodel.h
│   ├── models/       # 数据模型
│   │   ├── student.h
│   │   ├── course.h
│   │   └── enrollment.h
│   ├── views/        # 视图类
│   │   ├── studentview.h
│   │   ├── adminview.h
│   │   └── loginview.h
│   └── controllers/  # 控制器
│       ├── studentcontroller.h
│       └── admincontroller.h
│
├── src/              # 源文件目录
│   ├── database/
│   │   ├── dbmanager.cpp
│   │   └── querymodel.cpp
│   ├── models/
│   │   ├── student.cpp
│   │   ├── course.cpp
│   │   └── enrollment.cpp
│   ├── views/
│   │   ├── studentview.cpp
│   │   ├── adminview.cpp
│   │   └── loginview.cpp
│   └── controllers/
│       ├── studentcontroller.cpp
│       └── admincontroller.cpp
│
└── CMakeLists.txt    # CMake 配置文件